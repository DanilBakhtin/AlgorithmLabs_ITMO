#include "pch.h"
#include "CppUnitTest.h"
#include "../DynamicArray/MyArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMyArray
{
	TEST_CLASS(UnitTestMyArray)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
			MyArray<int> a;

			Assert::IsTrue(a.size() == 0);
			Assert::IsTrue(a.capacity() == 16);
		}
		TEST_METHOD(CapacityConstructor)
		{
			MyArray<int> a(5);

			Assert::IsTrue(a.size() == 0);
			Assert::IsTrue(a.capacity() == 5);
		}
		TEST_METHOD(CopyConstructor)
		{
			MyArray<int> a(5);
			a.insert(1);
			a.insert(15);
			a.insert(3);

			MyArray<int> b(a);

			Assert::IsTrue(a.size() == b.size());
			Assert::IsTrue(a.capacity() == b.capacity());

			for (size_t i = 0; i < a.size(); i++)
				Assert::IsTrue(a[i] == b[i]);

		}
		TEST_METHOD(MoveConstructor)
		{
			MyArray<int> a(5);
			a.insert(1);
			a.insert(15);
			a.insert(3);
			a.insert(2);

			MyArray<int> b = std::move(a);

			Assert::IsTrue(b.size() == 4);

			Assert::IsTrue(b[0] == 1);
			Assert::IsTrue(b[1] == 15);
			Assert::IsTrue(b[2] == 3);
			Assert::IsTrue(b[3] == 2);
		}
		TEST_METHOD(InsertToStart)
		{
			MyArray<int> a(5);
			a.insert(1);

			Assert::IsTrue(a[0] == 1);

			a.insert(15);
			a.insert(3);
			a.insert(2);

			Assert::IsTrue(a.size() == 4);
			
			a.insert(0, 10);

			Assert::IsTrue(a.size() == 5);
			Assert::IsTrue(a[0] == 10);
		}
		TEST_METHOD(InsertToMiddle)
		{
			MyArray<int> a(5);
			a.insert(1);
			a.insert(15);
			a.insert(3);
			a.insert(2);

			Assert::IsTrue(a.size() == 4);

			a.insert(2, 10);

			Assert::IsTrue(a.size() == 5);
			Assert::IsTrue(a[2] == 10);
		}
		TEST_METHOD(InsertToEnd)
		{
			MyArray<int> a(5);
			a.insert(1);
			a.insert(15);
			a.insert(3);
			a.insert(2);

			Assert::IsTrue(a.size() == 4);

			a.insert(10);

			Assert::IsTrue(a.size() == 5);
			Assert::IsTrue(a[a.size()-1] == 10);
		}
		TEST_METHOD(RemoveFirst)
		{
			MyArray<int> a(4);
			a.insert(1);
			a.insert(15);
			a.insert(3);
			a.insert(2);

			Assert::IsTrue(a.size() == 4);

			a.remove(0);

			Assert::IsTrue(a.size() == 3);
			Assert::IsTrue(a[0] == 15);
			Assert::IsTrue(a[1] == 3);
			Assert::IsTrue(a[2] == 2);

		}
		TEST_METHOD(RemoveMiddle)
		{
			MyArray<int> a(5);
			a.insert(1);
			a.insert(15);
			a.insert(3);
			a.insert(2);
			a.insert(97);

			Assert::IsTrue(a.size() == 5);

			a.remove(2);

			Assert::IsTrue(a.size() == 4);
			Assert::IsTrue(a[0] == 1);
			Assert::IsTrue(a[1] == 15);
			Assert::IsTrue(a[2] == 2);
			Assert::IsTrue(a[3] == 97);

		}
		TEST_METHOD(RemoveLast)
		{
			MyArray<int> a(4);
			a.insert(1);
			a.insert(15);
			a.insert(3);
			a.insert(2);

			Assert::IsTrue(a.size() == 4);

			a.remove(a.size() - 1);

			Assert::IsTrue(a.size() == 3);
			Assert::IsTrue(a[0] == 1);
			Assert::IsTrue(a[1] == 15);
			Assert::IsTrue(a[2] == 3);

		}
		TEST_METHOD(IteratorHasNext)
		{
			MyArray<int> a(4);
			a.insert(1);
			a.insert(15);
			a.insert(3);
			a.insert(2);
			
			int sl = 0;

			for (auto it = a.iterator(); it.hasNext(); it.next())
				Assert::IsTrue(it.get() == a[sl++]);

		}
		TEST_METHOD(IteratorReverseHasNext)
		{
			MyArray<int> a(4);
			a.insert(1);
			a.insert(15);
			a.insert(3);
			a.insert(2);

			int sl = a.size() - 1;

			for (auto it = a.reverseIterator(); it.hasNext(); it.next())
				Assert::IsTrue(it.get() == a[sl--]);

		}
		TEST_METHOD(StringDefaultConstructor)
		{
			MyArray<std::string> a;

			Assert::IsTrue(a.size() == 0);
			Assert::IsTrue(a.capacity() == 16);
		}
		TEST_METHOD(StringCapacityConstructor)
		{
			MyArray<std::string> a(5);

			Assert::IsTrue(a.size() == 0);
			Assert::IsTrue(a.capacity() == 5);
		}	
		TEST_METHOD(StringCopyConstructor)
		{	
			MyArray<std::string> a(5);
			a.insert("1");
			a.insert("15");
			a.insert("3");

			MyArray<std::string> b = a;

			Assert::IsTrue(a.size() == b.size());
			Assert::IsTrue(a.capacity() == b.capacity());

			for (size_t i = 0; i < a.size(); i++)
				Assert::IsTrue(a[i] == b[i]);

		}
		TEST_METHOD(StringMoveConstructor)
		{
			MyArray<std::string> a(5);
			a.insert("1");
			a.insert("15");
			a.insert("3");
			a.insert("2");

			MyArray<std::string> b = std::move(a);

			Assert::IsTrue(b.size() == 4);

			Assert::IsTrue(b[0] == "1");
			Assert::IsTrue(b[1] == "15");
			Assert::IsTrue(b[2] == "3");
			Assert::IsTrue(b[3] == "2");
		}
		TEST_METHOD(StringInsertToStart)
		{
			MyArray<std::string> a(5);
			a.insert("1");

			Assert::IsTrue(a[0] == "1");

			a.insert("15");
			a.insert("3");
			a.insert("2");

			Assert::IsTrue(a.size() == 4);

			a.insert(0, "10");

			Assert::IsTrue(a.size() == 5);
			Assert::IsTrue(a[0] == "10");
		}
		TEST_METHOD(StringInsertToMiddle)
		{
			MyArray<std::string> a(5);
			a.insert("1");
			a.insert("15");
			a.insert("3");
			a.insert("2");

			Assert::IsTrue(a.size() == 4);

			a.insert(2, "10");

			Assert::IsTrue(a.size() == 5);
			Assert::IsTrue(a[2] == "10");
		}
		TEST_METHOD(StringInsertToEnd)
		{
			MyArray<std::string> a(5);
			a.insert("1");
			a.insert("15");
			a.insert("3");
			a.insert("2");

			Assert::IsTrue(a.size() == 4);

			a.insert("10");

			Assert::IsTrue(a.size() == 5);
			Assert::IsTrue(a[a.size() - 1] == "10");
		}
		TEST_METHOD(StringRemoveFirst)
		{
			MyArray<std::string> a(4);
			a.insert("1");
			a.insert("15");
			a.insert("3");
			a.insert("2");

			Assert::IsTrue(a.size() == 4);

			a.remove(0);

			Assert::IsTrue(a.size() == 3);
			Assert::IsTrue(a[0] == "15");
			Assert::IsTrue(a[1] == "3");
			Assert::IsTrue(a[2] == "2");

		}
		TEST_METHOD(StringRemoveMiddle)
		{
			MyArray<std::string> a(5);
			a.insert("1");
			a.insert("15");
			a.insert("3");
			a.insert("2");
			a.insert("97");

			Assert::IsTrue(a.size() == 5);

			a.remove(2);

			Assert::IsTrue(a.size() == 4);
			Assert::IsTrue(a[0] == "1");
			Assert::IsTrue(a[1] == "15");
			Assert::IsTrue(a[2] == "2");
			Assert::IsTrue(a[3] == "97");

		}
		TEST_METHOD(StringRemoveLast)
		{
			MyArray<std::string> a(4);
			a.insert("1");
			a.insert("15");
			a.insert("3");
			a.insert("2");

			Assert::IsTrue(a.size() == 4);

			a.remove(a.size() - 1);

			Assert::IsTrue(a.size() == 3);
			Assert::IsTrue(a[0] == "1");
			Assert::IsTrue(a[1] == "15");
			Assert::IsTrue(a[2] == "3");

		}
	};
}
