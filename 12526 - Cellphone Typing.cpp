#include <iostream>
#include <cstddef>
#include <string>
#include <vector>
#include <iomanip>

#define MAX 26
//-97
class Trie
{
    public:
        bool is_leaf = false;
        int nodes = 0;
        Trie *character[MAX];
        Trie();
        void insert(std::string);
        bool have_child(Trie&);
        int amount(std::string);
    private:
};

Trie::Trie()
{
        for(int i = 0; i < MAX; ++i)
            character[i] = nullptr;
}

void Trie::insert(std::string value)
{
    Trie *current_node = this;
    for(int i = 0; i < value.size(); ++i)
    {
        if(current_node->character[value[i] - 97] == nullptr)
        {
            current_node->nodes++;
            current_node->character[value[i] - 97] = new Trie();
        }
        current_node = current_node->character[value[i] - 97];
    }
    current_node->is_leaf = true;
}

int count(int i, Trie *head, std::string &key)
{
    if(i == key.size()) return 0;
    if(head->is_leaf || head->nodes > 1) return 1 + count(i+1, head->character[key[i] - 97],key);
    else return count(i+1, head->character[key[i] - 97],key);
}

int main()
{

   double tests;
   while(std::cin >> tests)
   {
       Trie *head = new Trie();
       head->is_leaf = true;
       std::vector<std::string> words;
       std::string input;
       for(int i = 0; i < tests; ++i)
       {
           std::cin >> input;
           words.push_back(input);
           head->insert(input);
       }
       double result = 0;
       for(std::string v : words)
            result += count(0,head,v);
        printf("%.2lf\n", result/tests);
        //std::cout << std::setprecision(2) << std::fixed << result / tests << std::endl;
   }
/**
   Trie head;
   head.insert("hi");
   head.insert("he");
   head.insert("h");
   std::cout << head.amount("hi") << std::endl;
      std::cout << head.amount("he") << std::endl;

         std::cout << head.amount("h") << std::endl;
**/
    return 0;
}
