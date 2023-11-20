// File Line: 13
// RVA: 0x5C88B0
void __fastcall UFG::UIList::UIList(UFG::UIList *this, UFG::UIScreen *screen)
{
  UFG::qList<UFG::UIItem,UFG::UIItem,1,0> *v2; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::UISlot,UFG::UISlot,1,0> *v3; // [rsp+48h] [rbp+10h]

  this->vfptr = (UFG::UIWidgetVtbl *)&UFG::UIWidget::`vftable;
  v2 = &this->m_items;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v3 = &this->m_slots;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  this->m_selectedItem = 0i64;
  this->m_selectedItemIndex = -1;
  this->m_firstVisibleItem = 0i64;
  this->m_firstVisibleItemIndex = -1;
  this->m_highlightedSlot = 0i64;
  this->m_screen = screen;
  this->vfptr = (UFG::UIWidgetVtbl *)&UFG::UIList::`vftable;
  UFG::qString::qString(&this->m_initData.m_pathToWidget);
}

// File Line: 20
// RVA: 0x5CE070
void __fastcall UFG::UIList::~UIList(UFG::UIList *this)
{
  UFG::UIList *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::UIWidgetVtbl *)&UFG::UIList::`vftable;
  UFG::qString::~qString(&this->m_initData.m_pathToWidget);
  UFG::UIWidget::~UIWidget((UFG::UIWidget *)&v1->vfptr);
}

