// File Line: 12
// RVA: 0x5CDFA0
void __fastcall UFG::UIItemText::~UIItemText(UFG::UIItemText *this)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_m_options; // rdi
  UFG::UIItemText *mNext; // rbx
  UFG::UIItemVtbl *vfptr; // rcx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *mPrev; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v8; // rcx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v9; // rax

  this->vfptr = (UFG::UIItemVtbl *)&UFG::UIItemText::`vftable;
  p_m_options = &this->m_options;
  mNext = (UFG::UIItemText *)this->m_options.mNode.mNext;
  if ( mNext != (UFG::UIItemText *)&this->m_options )
  {
    do
    {
      vfptr = mNext->vfptr;
      mPrev = mNext->mPrev;
      vfptr->handleMessage = (bool (__fastcall *)(UFG::UIItem *, UFG::UIMessage *))mPrev;
      mPrev->mPrev = (UFG::qNode<UFG::UIItem,UFG::UIItem> *)vfptr;
      mNext->vfptr = (UFG::UIItemVtbl *)mNext;
      mNext->mPrev = (UFG::qNode<UFG::UIItem,UFG::UIItem> *)mNext;
      UFG::qString::~qString((UFG::qString *)mNext);
      operator delete[](mNext);
      mNext = (UFG::UIItemText *)p_m_options->mNode.mNext;
    }
    while ( mNext != (UFG::UIItemText *)p_m_options );
  }
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(p_m_options);
  v6 = p_m_options->mNode.mPrev;
  v7 = p_m_options->mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_m_options->mNode.mPrev = &p_m_options->mNode;
  p_m_options->mNode.mNext = &p_m_options->mNode;
  UFG::qString::~qString(&this->m_text);
  this->vfptr = (UFG::UIItemVtbl *)&UFG::UIItem::`vftable;
  v8 = this->mPrev;
  v9 = this->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->mPrev = &this->UFG::qNode<UFG::UIItem,UFG::UIItem>;
  this->mNext = &this->UFG::qNode<UFG::UIItem,UFG::UIItem>;
}

