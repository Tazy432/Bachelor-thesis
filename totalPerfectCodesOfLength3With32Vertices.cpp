#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<string> binaryNumberGenerator(const int length)
{
    vector<string> binaries;
    int max = 1 << length;  // 2^length
    for (int i = 0; i < max; ++i) {
        binaries.push_back(std::bitset<5>(i).to_string());
    }
    return binaries;
}
bool checkIfInVector(string number,vector<string> numbers)
{
    for(int i=0;i<numbers.size();i++)
    {
        if(number==numbers[i])
            return true;
    }
    return false;
}
int nrOf1InVector(vector<int> distante)
{
    int values=0;
    for(int i=0;i<distante.size();i++)
    {
        if(distante[i]==1)
        {
            values++;
        }
    }
    return values;
}
int hammingDistance(const std::string binary1,const std::string binary2)
{
    if(binary1.size()!=binary2.size())
    {
        std::cout<<"The numbers dont have the same length";
        return -1;
    }
    int distance=0;
    for(int i=0;i<binary1.size();i++)
    {
        if(binary1[i]!=binary2[i])
        {
            distance++;
        }
    }
    return distance;
}
std::vector<std::vector<std::string>> generateGroupsOfThree() {
    std::vector<std::string> binaries = binaryNumberGenerator(3);
    std::vector<std::vector<std::string>> groups;

    // Create all possible combinations of 3 different binary strings
    int n = binaries.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { 
            for(int k=j+1;k<n;++k)
            {
                groups.push_back({binaries[i], binaries[j],binaries[k]});
            }  
            
            
        }
    }

    return groups;
}
bool isInVector(int number,vector<int> numbers)
{
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i]==number)
        {
            return true;
        }
    }
    return false;
}
bool isPerfectCode(vector<string> testCodewords)
{
    
    vector<string> allCodewords=binaryNumberGenerator(3);
    vector<vector<int>> distances;
    for(int i=0;i<allCodewords.size();i++)
    {
        vector<int> distanceFromTest;
        for(int j=0;j<testCodewords.size();j++)
        {
            distanceFromTest.push_back(hammingDistance(allCodewords[i],testCodewords[j]));
        }
        distances.push_back(distanceFromTest);
        distanceFromTest.clear();
    }
    for(int i=0;i<allCodewords.size();i++)
    {
        cout<<distances[i][0]<<" "<<distances[i][1]<<" "<<distances[i][2]<<endl;
        if((nrOf1InVector(distances[i])>1) || (nrOf1InVector(distances[i])==0 && checkIfInVector(allCodewords[i],testCodewords)==false))
        {
            cout<<testCodewords[0]<<" "<<testCodewords[1]<<" "<<testCodewords[2]<<" is NOT a total perfect code"<<endl;
            return false;
        }

    }
    cout<<testCodewords[0]<<" "<<testCodewords[1]<<" "<<testCodewords[2]<<" is a total perfect code"<<endl;
    return true;
    
}
int main()
{
    vector<string> mor=binaryNumberGenerator(5);
    vector<vector<string>> groups=generateGroupsOfThree();
    int nrOfTotalPerfectCodes=0;
    for(int i=0;i<groups.size();i++)
    {
        if(isPerfectCode(groups[i]))
            nrOfTotalPerfectCodes++;
        
    }
    cout<<"When working with the Hamming graph(5,2) , and groups of 3 codewords we have "<<nrOfTotalPerfectCodes<<" total perfect codes"<<endl;

    return 0;
}