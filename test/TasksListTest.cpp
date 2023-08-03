//
// Created by Mattia Benincasa on 19/07/23.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TasksList.h"

int TasksList::total = 0;

class TasksListSuitRead : public::testing::Test {
protected:
    void SetUp() override {
       std::string name = "fileTest.data";
       std::ofstream fout;
       fout.open(name);
       fout << "ListName" << std::endl;
       fout << 1 << std::endl;
       fout.close();
    }

    void TearDown() override {
        char name[14] = "fileTest.data";
        remove(name);
    }
};

TEST_F(TasksListSuitRead, ReadingTest) {
    TasksList tasksList("fileTest");

    std::list lists = tasksList.getList();
    auto findList = std::find(lists.begin(), lists.end(), "ListName");
    ASSERT_EQ("ListName", findList->getName());
    ASSERT_EQ(1, tasksList.getTotal());
}


//Testing if addList method write on the file Test.data
TEST(TasksList, WritingTest) {
    TasksList tasksList("Test");

    std::string name = "TestName";
    List list(name);
    tasksList.addList(list);

    std::ifstream fin;
    std::string writtenList;
    int countTask;
    fin.open("Lists.data");
    if(!fin)
        return;
    while(fin.good()){
        fin >> writtenList;
        fin >> countTask;
    }

    ASSERT_EQ("TestName", writtenList);
    ASSERT_EQ(0, countTask);
    tasksList.removeList(name);
    tasksList.save();
    fin.close();

}

TEST(TasksList, addRemoveLists){
    TasksList system;
    std::string name = "User";
    List list(name);
    system.addList(list);
    ASSERT_THAT(system.getList(), ::testing::Contains(list));
    system.removeList(name);
    ASSERT_THAT(system.getList(), ::testing::IsEmpty());
}

