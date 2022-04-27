#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>

#include "../RectangleCpp/source/Rectangle.cpp"
#include "../RectangleCpp/source/Point.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(RectangleTest)
	{
	public:
		TEST_METHOD(RectangleTest_1)
		{
			Assert::ExpectException<std::invalid_argument>([]() {
				Rectangle rectangle = Rectangle(Point(0, 0), -1, 0, Color());
			});
			Assert::ExpectException<std::invalid_argument>([]() {
				Rectangle rectangle = Rectangle(Point(0, 0), 0, -1, Color());
			});
		}

		TEST_METHOD(RectangleTest_2)
		{
			Rectangle rectangle = Rectangle(Point(0, 0), 1, 1, Color());
			Assert::AreEqual(Point(1, 1).x, rectangle.getSecondPoint().x);
			Assert::AreEqual(Point(1, 1).y, rectangle.getSecondPoint().y);
		}
	};
}
