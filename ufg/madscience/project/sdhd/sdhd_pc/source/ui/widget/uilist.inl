// File Line: 13
// RVA: 0x5C88B0
void __fastcall UFG::UIList::UIList(UFG::UIList *this, UFG::UIScreen *screen)
{
  this->vfptr = (UFG::UIWidgetVtbl *)&UFG::UIWidget::`vftable;
  this->m_items.mNode.mPrev = &this->m_items.mNode;
  this->m_items.mNode.mNext = &this->m_items.mNode;
  this->m_slots.mNode.mPrev = &this->m_slots.mNode;
  this->m_slots.mNode.mNext = &this->m_slots.mNode;
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
  this->vfptr = (UFG::UIWidgetVtbl *)&UFG::UIList::`vftable;
  UFG::qString::~qString(&this->m_initData.m_pathToWidget);
  UFG::UIWidget::~UIWidget(this);
}

