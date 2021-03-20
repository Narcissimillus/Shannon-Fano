#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// tree node
struct node
{
    // one or zero val
    int oz;
    // symbol
    char s[20];
    // frequency
    int freq[20];
    // leaf val
    int leaf = 0;
};

typedef struct node node;

node sortFreqs(node n, int noFreqs)
{
    // bubble sort
    for (int i = 0; i < noFreqs; i++)
    {
        for (int j = 0; j < noFreqs - 1; j++)
        {
            if ((n.freq[j]) < (n.freq[j + 1]))
            {
                char aus = n.s[j];
                n.s[j] = n.s[j + 1];
                n.s[j + 1] = aus;

                int aux = n.freq[j];
                n.freq[j] = n.freq[j + 1];
                n.freq[j + 1] = aux;
            }
        }
    }
    return n;
}

node codetree[50];
int index = 1;

void splitEvenly(node n, int noFreqs)
{
    if(noFreqs == 1)
    {

    }
    else
    {
        int sum1 = n.freq[0];
        node list1;
        list1.oz = 0;
        int k1 = 0;
        list1.s[0] = n.s[0];
        list1.freq[0] = n.freq[0];

        int sum2 = n.freq[1];
        node list2;
        list2.oz = 1;
        int k2 = 0;
        list2.s[0] = n.s[1];
        list2.freq[0] = n.freq[1];

        for(int i = 2; i < noFreqs; i++)
        {
            if(sum1 > sum2)
            {
                k2++;
                list2.s[k2] = n.s[i];
                list2.freq[k2] = n.freq[i];
                sum2 += n.freq[i];
            }
            else
            {
                k1++;
                list1.s[k1] = n.s[i];
                list1.freq[k1] = n.freq[i];
                sum1 += n.freq[i];
            }
        }
        codetree[index] = list1;
        if(k1 == 0)
        {
            codetree[index].leaf = 1;
        }
        index++;
        codetree[index] = list2;
        if(k2 == 0)
        {
            codetree[index].leaf = 1;
        }
        index++;

        splitEvenly(list1, k1 + 1);
        splitEvenly(list2, k2 + 1);
    }
}

void displayCodes(int k)
{
    for(int i = 0; i < k; i++)
    {
        cout << codetree[0].s[i] << " ";
        int temp = 1;
        while(temp < index)
        {
            int found = 0;
            // search if node contains symbol
            for(int j = 0; j < 20; j++)
            {
                if(codetree[temp].s[j] == codetree[0].s[i])
                    found = 1;
            }
            if(found == 1)
            {
                cout << codetree[temp].oz;
            }
            // break when reached leaf
            if(found == 1 && codetree[temp].leaf == 1)
            {
                cout << endl;
                temp = index;
            }
            temp++;
        }
    }
}

int main()
{
    string line;
    ifstream f("data.in");
    int k = 0;
    node n;
    getline(f, line);
    for(int i = 0; i < line.length(); i++){
        if (line[i] != ' '){
            codetree[0].s[k] = line[i];
            cout << codetree[0].s[k] << " ";
            k++;
        }
    }
    cout << endl;
    k = 0;
    while (getline(f, line, ' ')){
        codetree[0].freq[k] = stoi(line);
        cout << codetree[0].freq[k] << " ";
        k++;
    }
    cout << endl;

    codetree[0] = sortFreqs(codetree[0], k);
    for(int i = 0; i < k; i++)
    {
        cout << codetree[0].freq[i] << " ";
    }
    splitEvenly(codetree[0], k);
    cout << endl;
    displayCodes(k);
    f.close();
    return 0;
}
