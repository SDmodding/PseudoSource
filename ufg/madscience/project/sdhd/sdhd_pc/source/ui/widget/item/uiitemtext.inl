// File Line: 12
// RVA: 0x5CDFA0
void __fastcall UFG::UIItemText::~UIItemText(UFG::UIItemText *this)
{
  UFG::UIItemText *v1; // rsi
  UFG::qList<UFG::qString,UFG::qString,1,0> *v2; // rdi
  UFG::qString *v3; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v8; // rdx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v9; // rcx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v10; // rax

  v1 = this;
  this->vfptr = (UFG::UIItemVtbl *)&UFG::UIItemText::`vftable';
  v2 = &this->m_options;
  v3 = (UFG::qString *)this->m_options.mNode.mNext;
  if ( v3 != (UFG::qString *)&this->m_options )
  {
    do
    {
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mPrev;
      UFG::qString::~qString(v3);
      operator delete[](v3);
      v3 = (UFG::qString *)v2->mNode.mNext;
    }
    while ( v3 != (UFG::qString *)v2 );
  }
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(v2);
  v6 = v2->mNode.mPrev;
  v7 = v2->mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qString::~qString(&v1->m_text);
  v1->vfptr = (UFG::UIItemVtbl *)&UFG::UIItem::`vftable';
  v8 = (UFG::qNode<UFG::UIItem,UFG::UIItem> *)&v1->mPrev;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = v8;
  v8->mNext = v8;
}

