#include <gtest/gtest.h>
#include "source.cpp"
namespace{
    class ClassDeclaration : public testing::Test {
    public:
        occurrences obj;
        ClassDeclaration(){
            obj;
        }
    };
}
std::list<history> hList;

TEST(Words,FindTwoOccurrencesOutOfTwo){
    occurrences A;
    int count = A.findAllOccurances("aaa bbb ccc aaa bbb ccc","aaa bbb ccc",0,hList);
    EXPECT_EQ(count,2);
}
TEST(Words,FindZeroOccurrencesOutOfZero){
    occurrences A;
    int count = A.findAllOccurances("aaa bbb ccc aaa bbb ccc","aaa ccc bbb",0,hList);
    EXPECT_EQ(count,0);
}
TEST(Words,FindTwoInFullAs){
    //occurrences A;
    //A.filter("aaa bbb ccc aaa bbb ccc");
    occurrences A;
    int count = A.findAllOccurances("aaa aaa aaa aaa","aaa aaa aaa",0,hList);
    EXPECT_EQ(count,2);
    //EXPECT_EQ(A.vec.size(),3);
}
TEST(Words,FindInEmptySample){
    occurrences A;
    int count = A.findAllOccurances("","aaa ccc bbb",0,hList);
    EXPECT_EQ(count,0);
}
TEST(Words,FindNoInSampleWithOneWord){
    occurrences A;
    int count = A.findAllOccurances("aaa","aaa ccc bbb",0,hList);
    EXPECT_EQ(count,0);
}
TEST(Words,FindNoData){
    occurrences A;
    int count = A.findAllOccurances("aaa bbb ccc aaa bbb ccc","",0,hList);
    EXPECT_EQ(count,0);
}

TEST(NewT,historyNotEmpty){
    occurrences A;
	hList.clear();
    int count = A.findAllOccurances("aaa bbb ccc aaa bbb ccc","aaa bbb ccc",0,hList);
	count = A.findAllOccurances("aaa bbb ccc aaa bbb ccc","aaa bbb ccc",0,hList);
	bool eq=true;
	if(hList.empty()){
		eq=false;	
	}
	ASSERT_EQ(true, eq);
}

TEST(NewT,historiesAreEqual){
    occurrences A;
	hList.clear();
    int count = A.findAllOccurances("aaa bbb ccc aaa bbb ccc","aaa bbb ccc",0,hList);
	std::list<history> hListT;
	history curT;
	curT.addNote("aaa bbb ccc aaa bbb ccc","aaa bbb ccc",count);
	hListT.push_back(curT);
	count = A.findAllOccurances("aaa bbb ccc aaa bbb ccc","aaa bbb ccc",0,hList);
	history curT1;
	curT1.addNote("aaa bbb ccc aaa bbb ccc","aaa bbb ccc",count);
	hListT.push_back(curT1);
	bool eq=true;
	if(hList.size() == hListT.size()){
			while(!hList.empty() || !hListT.empty()){
				if(hList.front().str==hListT.front().str && hList.front().substr==hListT.front().substr && hList.front().count==hListT.front().count)
					;
				else
					eq=false;
				hList.pop_front();
				hListT.pop_front();
			}
		}
		ASSERT_EQ(true, eq);
}

int main(int argc, char *argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}