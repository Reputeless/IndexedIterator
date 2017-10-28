//----------------------------------------------------------------------------------------
//
//	siv::IndexedIterator
//	Indexed iterator library for modern C++
//
//	Copyright (C) 2017 Ryo Suzuki <reputeless@gmail.com>
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files(the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions :
//	
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//	
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.
//
//----------------------------------------------------------------------------------------

# pragma once
# include <iterator>
# include <functional>

namespace siv
{
	template <class Iterator>
	class IndexedIterator
	{
	private:

		size_t m_index = 0;

		Iterator m_it;

	public:

		using iterator_category	= typename std::iterator_traits<Iterator>::iterator_category;
		using value_type		= typename std::iterator_traits<Iterator>::value_type;
		using difference_type	= typename std::iterator_traits<Iterator>::difference_type;
		using pointer			= typename std::iterator_traits<Iterator>::pointer;
		using reference			= typename std::iterator_traits<Iterator>::reference;

		IndexedIterator(size_t index, Iterator it)
			: m_index(index)
			, m_it(it) {}

		IndexedIterator& operator ++()
		{
			++m_index;

			++m_it;
		
			return *this;
		}

		auto operator *() const noexcept
		{
			if constexpr (std::is_lvalue_reference_v<decltype(*m_it)>)
			{
				return std::make_pair(m_index, std::ref(*m_it));
			}
			else
			{
				return std::make_pair(m_index, *m_it);
			}
		}

		bool operator ==(const IndexedIterator& other) const
		{
			return m_it == other.m_it;
		}

		bool operator !=(const IndexedIterator& other) const
		{
			return m_it != other.m_it;
		}
	};

	namespace detail
	{
		template <class Range>
		class Indexed_impl
		{
		private:

			const Range& m_range;

		public:

			Indexed_impl(const Range& range)
				: m_range(range) {}

			auto begin() const
			{
				return IndexedIterator<decltype(std::begin(m_range))>(0, std::begin(m_range));
			}

			auto end() const
			{
				return IndexedIterator<decltype(std::begin(m_range))>(std::size(m_range), std::end(m_range));
			}
		};
	}

	template <class Range>
	inline detail::Indexed_impl<Range> Indexed(const Range& range)
	{
		return detail::Indexed_impl<Range>(range);
	}
}
