//
// Created by Mattia Benincasa on 12/07/23.
//
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../List.h"

class ListSuitWrite : public::testing::Test{

protected:
    void SetUp() override {
        std::string name = "Test";
        std::string ListName = "TestList";
        user.setName(ListName);
        std::string desc = "Test description";
        Date d;
        Clock t;
        Task task(name, desc, d, t);
        user.addTask(task, ListName);
    }

    void TearDown() override {
        std::string ListName = "TestList";
        std::string name = "Test";
        user.removeTask(name, ListName);
        user.saveTasks();
    }

    List user;
};

//In the setUp I have created a Task that I have added to the list "user".
//In the next test I read the values on the file "TestList" and I write them in a new Task.
//Then I compare this Task with the values insert in the setUp to test the Writing operation of the addTask Method

TEST_F(ListSuitWrite, WritingTest) {
    std::ifstream fin;
    Task writtenTask;
    fin.open("TestList.data");
    if(!fin)
        return;
    while(fin.good())
        fin >> writtenTask;

    ASSERT_EQ("Test", writtenTask.getName());
    ASSERT_EQ("Test description", writtenTask.getDescription());
    ASSERT_EQ(1, writtenTask.getDate().getDay());
    ASSERT_EQ(1, writtenTask.getDate().getMonth());
    ASSERT_EQ(2023, writtenTask.getDate().getYear());
    ASSERT_EQ(0, writtenTask.getTime().getHour());
    ASSERT_EQ(0, writtenTask.getTime().getMinute());
    ASSERT_FALSE(writtenTask.getCompleted());

}

class ListSuitRead : public::testing::Test {
protected:
    void SetUp() override {
        std::string fileName = "FileTest.data";
        std::ofstream fout;
        fout.open(fileName);
        fout << "Test" << std::endl;
        fout << "description of the task" << std::endl;
        fout << 2 << std::endl;
        fout << 2 << std::endl;
        fout << 2024 << std::endl;
        fout << 11 << std::endl;
        fout << 11 << std::endl;
        fout << 1 << std::endl;
        fout.close();
    }

    void TearDown() override {
        char name[14] = "FileName.data";
        remove(name);
    }

};

//I have written on file "FileTest.data" some values for a task attributes.
//Then, in the next Test, I have created a List object whose constructor read
//directly from the file I have created in the setUp the attributes. Next, I control that all the attributes are
//read correctly.

TEST_F(ListSuitRead, ReadingTest){
    std::string name = "FileTest";
    List list(name);
    std::map tasks = list.getTasks();
    auto findTask = tasks.find("Test");
    ASSERT_EQ(findTask->first, "Test");
    ASSERT_EQ(findTask->second.getDescription(), "description of the task");
    ASSERT_EQ(findTask->second.getDate().getDay(), 2);
    ASSERT_EQ(findTask->second.getDate().getMonth(), 2);
    ASSERT_EQ(findTask->second.getDate().getYear(), 2024);
    ASSERT_EQ(findTask->second.getTime().getMinute(), 11);
    ASSERT_EQ(findTask->second.getTime().getHour(), 11);
    ASSERT_TRUE(findTask->second.getCompleted());
}


TEST(List, AddRemoveTasks){
    std::string listName;
    List user;
    std::string taskName = "TaskName";
    std::string desc;
    Date d;
    Clock t;
    Task task(taskName, desc, d, t);
    user.addTask(task, listName);
    ASSERT_TRUE(user.findTask(taskName));
    user.removeTask(taskName, listName);
    ASSERT_FALSE(user.findTask(taskName));
}