#pragma once
#include <functional>
#include <iterator>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>

namespace edulib
{
	namespace containers
	{
		namespace detail
		{
			template<typename T>
			struct HeapNode
			{
				alignas(T) unsigned char objBuffer[sizeof(T)];
				HeapNode* left;
				HeapNode* right;
				HeapNode* parent;

				T* value_ptr()
				{
					return reinterpret_cast<T*>(objBuffer);
				}
				const T* value_ptr() const
				{
					return reinterpret_cast<const T*>(objBuffer);
				}

				T& operator*()
				{
					return *value_ptr();
				}
				const T& operator*() const
				{
					return *value_ptr();
				}
				T* operator->()
				{
					return value_ptr();
				}
				const T* operator->() const
				{
					return value_ptr();
				}
			};
		}

		template<typename T, typename Compare = std::less<>, typename Alloc = std::allocator<T>>
		class Heap
		{
			using node_type = detail::HeapNode<T>;
			friend node_type;

			template<typename... Ts>
			node_type* BuyNode(Ts&&... vs)
			{
				auto newMem = reinterpret_cast<node_type*>(alloc.allocate(sizeof(node_type)));
				auto newNode = ::new(newMem) node_type;

				alloc.construct(newNode->value_ptr(), std::forward<Ts>(vs)...);

				return newNode;
			}

		public:
			using alloc_traits = std::allocator_traits<Alloc>;
			using value_type = typename alloc_traits::value_type;
			using reference = T&;
			using const_reference = const reference;
			using pointer = typename alloc_traits::pointer;
			using const_pointer = typename alloc_traits::const_pointer;
			using size_type = typename alloc_traits::size_type;
			using difference_type = typename alloc_traits::difference_type;

			Heap()
				: root(nullptr)
			{}
			explicit Heap(Alloc a)
				: Heap()
				, alloc(std::move(a))
			{}
			Heap(Compare c)
				: Heap()
				, cmp(std::move(c))
			{}
			Heap(const Heap&);
			Heap& operator=(const Heap&);
			Heap(Heap&&);
			Heap& operator=(Heap&&);
			~Heap();

			void push(const_reference);
			void push(T&&);

			template<typename... Ts>
			void emplace(Ts&&...);

			void pop();
			value_type top() const;

		private:
			Alloc alloc;
			Compare cmp;
			node_type* root;
			size_type size;
		};
	}
}