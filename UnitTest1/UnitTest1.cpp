#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.3/lab11.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCalculateAverageGrade) {
            Student student = { "Doe", 2, CS, 80, 90, {0} }; 
            student.additional_grade.programming = 85;  
            double averageGrade = CalculateAverageGrade(student);

            Assert::AreEqual(85.0, averageGrade, 0.01); 
        }

        TEST_METHOD(TestIndexSort) {
            const int N = 3;
            Student students[N];
            students[0] = { "John", 3, CS, 80, 90, {0} }; 
            students[0].additional_grade.programming = 85;
            students[1] = { "Alice", 2, IT, 75, 85, {0} };
            students[1].additional_grade.numerical_methods = 80;
            students[2] = { "Bob", 4, ME, 85, 95, {0} }; 
            students[2].additional_grade.pedagogy = 90;
            std::unique_ptr<int[]> indices(IndexSort(students, N));

            Assert::AreEqual(std::string("Bob"), students[indices[0]].surname, L"First should be Bob with the highest pedagogy grade.");
            Assert::AreEqual(std::string("John"), students[indices[1]].surname, L"Second should be John with the second highest programming grade.");
            Assert::AreEqual(std::string("Alice"), students[indices[2]].surname, L"Last should be Alice with the lowest numerical methods grade.");
        }

        TEST_METHOD(TestBinarySearch) {
            const int N = 3;
            Student students[N];
            students[0] = { "Alice", 2, IT, 75, 85, {0} }; 
            students[0].additional_grade.numerical_methods = 80;
            students[1] = { "Bob", 4, ME, 85, 95, {0} }; 
            students[1].additional_grade.pedagogy = 90;
            students[2] = { "John", 3, CS, 80, 90, {0} }; 
            students[2].additional_grade.programming = 85;
            SortForBinarySearch(students, N); 
            bool found = BinarySearch(students, N, "John", 3, 85);

            Assert::IsTrue(found);
        }
	};
}
