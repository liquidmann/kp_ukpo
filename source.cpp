#ifndef UKPO2_Y_MYCLASS_H
#define UKPO2_Y_MYCLASS_H
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

class history{
public:
std::string str;
std::string substr;
int count;

void addNote(std::string, std::string, int);
};

void history::addNote(std::string str, std::string substr, int count){
	this->str=str;
	this->substr=substr;
	this->count=count;
}

class occurrences{
public:
    std::string sample;
    std::vector<std::string> vec;

    void filter(std::string sample){


        std::string data;

        int probel=0;

        for(int i=0;sample[i];i++){
            if(sample[i]==' ')
                probel++;
        }
        bool last=false,found;
        int samplepos, datapos, temp=0, counter=0;
        size_t startpos;
        for(int i=0; i<probel-1; !last){
            found = false;
            counter=0;
            datapos=0;
            samplepos=temp;
            startpos=temp;
            data.clear();
            while(counter<3){
                data.push_back(sample[samplepos]);
                datapos++;
                samplepos++;
                if(sample[samplepos]=='\0') {
                    last = true;
                    break;
                }

                if(sample[samplepos]==' ')
                    counter++;

                if(counter==1 && sample[samplepos]==' ')
                    temp=samplepos+1;
            }
            if(i==0)this->vec.push_back(data);
            for(int g=0;g<this->vec.size()+1;g++) {
                if(this->vec[g]==data && i>0) {
                    found = true;
                    break;
                }
                else if(i==0 || g<this->vec.size())
                    continue;
                else {
                    this->vec.push_back(data);
                    break;
                }
            }
            if(!found) {
				std::list<history> hList;
                int occur = findAllOccurances(sample, data, startpos,hList);

                //std::cout << "substring <" << data << "> has";
                //occur == 0 ? std::cout << "no occurrences" : std::cout << " been found " << occur << " times" << std::endl;
            }
            i++;
        }
    }
    int findAllOccurances(/*std::vector<size_t> & vec*/ std::string sample, std::string toSearch, size_t pos, std::list<history>& hList)
    {
        // Get the first occurrence
        int counter = 0;
        // Repeat till end is reached
        while( pos < sample.size())
        {
            // Add position to the vector
            if(toSearch.empty())break;
            if(sample.find(toSearch)!=std::string::npos)
            counter++;

            // Get the next occurrence from the current position
            pos =sample.find(toSearch, pos+1);
        }
		history cur;
		cur.addNote(sample, toSearch,counter);
		hList.push_back(cur);
        return counter;
    }
};
#endif