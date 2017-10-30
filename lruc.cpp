#include <iostream>
#include <vector>
using namespace std;


//--------------------------------------------------
class page
{
public:
  page(int pageId) { _pageId = pageId;};
  int getPageId() { return _pageId;};
  
  int _pageId  = -1;
  page* _next = nullptr;
  page* _prev = nullptr;
};

vector<page*> *pageLocationArray;
//--------------------------------------------------
class LRUC
{
public:
  LRUC(int size){
    _maxSize = size>0?size:1;
  };
  
  void refer(int pageId)
  {   
    if (!(*pageLocationArray)[pageId])
    {
      page* npg = new page(pageId);
      (*pageLocationArray)[pageId] = npg;

      if (_start == nullptr)
      {
        _start = npg;
        _end = npg;
        _pageCount++;     
      }
      else
      {
        if (_pageCount < _maxSize)
        {
          npg->_next = _start;
          _start->_prev = npg;
          _start = npg;

          _pageCount++;
        }
        else
        {
          (*pageLocationArray)[_end->getPageId()] = nullptr;
          page* prevEnd = _end->_prev;
          delete _end;
          _end = prevEnd;
          npg->_next = _start;
          _start->_prev = npg;
          _start = npg;
        }
      }
    }
    else // page already in memory
    {
      page* temp = (*pageLocationArray)[pageId];
      if (temp->_prev)
        temp->_prev->_next = temp->_next;
      if (temp->_next)
        temp->_next->_prev = temp->_prev;
      
      temp->_next = _start;
      _start->_prev = temp;
      _start = temp;      
    }   
  }
//private:
  int _maxSize = 0;
  int _pageCount = 0;
  page* _start = nullptr;
  page* _end   = nullptr;
};

//--------------------------------------------------
LRUC* getNewCache(int size)
{
  
  return new LRUC(size);
}
//--------------------------------------------------
void makeNewPageList(int size)
{
  pageLocationArray = new vector<page*>(size,nullptr);
}

//--------------------------------------------------
// To execute C++, please define "int main()"
int main() {
  
  // Cache size is 5, I got 10 pages
  LRUC* cache = getNewCache(5);
  makeNewPageList(10);
  cache->refer(1);
  cache->refer(5);
  cache->refer(2);
  cache->refer(4);
  cache->refer(1);
  cache->refer(6);
  cache->refer(2);
  
  cout << cache->_start->_pageId << endl;
  cout << cache->_start->_next->_pageId << endl;
  cout << cache->_start->_next->_next->_pageId << endl;
  cout << cache->_start->_next->_next->_next->_pageId << endl;
  //cout << cache->_start->_next->_next->_next->_next->_pageId << endl;
  //cout << cache->_start->_next->_next->_next->_next->_next->_pageId << endl;
  //cout << cache->_start->_next->_next->_next->_next->_next->_next->_pageId << endl;
  return 0;
}