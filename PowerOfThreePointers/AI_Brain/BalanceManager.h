#pragma once
#include "../Core/Node.h"
#include <algorithm>
class BalanceManager {
public:
    template<class T> static int GetHeight(Node<T>* n){ if(!n) return 0; return 1+std::max(GetHeight(n->GetPointer1()), GetHeight(n->GetPointer2())); }
    template<class T> static int GetBF(Node<T>* n){ if(!n) return 0; return GetHeight(n->GetPointer1())-GetHeight(n->GetPointer2()); }
    template<class T> static bool IsBalanced(Node<T>* n){ if(!n) return true; int bf=GetBF(n); if(bf<-1||bf>1) return false; return IsBalanced(n->GetPointer1())&&IsBalanced(n->GetPointer2()); }
};
