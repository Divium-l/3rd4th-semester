#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>

#include "../RectangleCpp/source/Color.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(ColorTest)
	{
	public:
		TEST_METHOD(ColorTest_1)
		{
			Assert::ExpectException<std::invalid_argument>([]() {
				Color color = Color(-1, 0, 0);
			});
			Assert::ExpectException<std::invalid_argument>([]() {
				Color color = Color(0, -1, 0);
			});
			Assert::ExpectException<std::invalid_argument>([]() {
				Color color = Color(0, 0, -1);
			});
		}

		TEST_METHOD(ColorTest_2)
		{
			Assert::ExpectException<std::invalid_argument>([]() {
				Color color = Color(256, 0, 0);
				});
			Assert::ExpectException<std::invalid_argument>([]() {
				Color color = Color(0, 256, 0);
			});
			Assert::ExpectException<std::invalid_argument>([]() {
				Color color = Color(0, 0, 256);
			});
		}
	};
}
