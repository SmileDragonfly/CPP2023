#include "pch.h"
#include "CppUnitTest.h"
#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestCheckARegex)
		{
			bool bCheck = Utils::CheckARegex("*TRANSACTION START*", "(?=\\*TRANSACTION START)");
			Assert::AreEqual(bCheck, true);
		}
	};
}
