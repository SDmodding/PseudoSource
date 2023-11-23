// File Line: 25
// RVA: 0x5CE7E0
void __fastcall UFG::UIWidget::~UIWidget(UFG::UIWidget *this)
{
  UFG::qList<UFG::UISlot,UFG::UISlot,1,0> *p_m_slots; // rbx
  UFG::qNode<UFG::UISlot,UFG::UISlot> *mPrev; // rcx
  UFG::qNode<UFG::UISlot,UFG::UISlot> *mNext; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v5; // rcx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v6; // rax

  this->vfptr = (UFG::UIWidgetVtbl *)&UFG::UIWidget::`vftable;
  p_m_slots = &this->m_slots;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_slots);
  mPrev = p_m_slots->mNode.mPrev;
  mNext = p_m_slots->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_slots->mNode.mPrev = &p_m_slots->mNode;
  p_m_slots->mNode.mNext = &p_m_slots->mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_items);
  v5 = this->m_items.mNode.mPrev;
  v6 = this->m_items.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->m_items.mNode.mPrev = &this->m_items.mNode;
  this->m_items.mNode.mNext = &this->m_items.mNode;
}

// File Line: 34
// RVA: 0x61DF10
void __fastcall UFG::UIWidget::addItem(UFG::UIWidget *this, UFG::UIItem *item)
{
  UFG::qNode<UFG::UIItem,UFG::UIItem> *mPrev; // rax

  mPrev = this->m_items.mNode.mPrev;
  mPrev->mNext = &item->UFG::qNode<UFG::UIItem,UFG::UIItem>;
  item->mPrev = mPrev;
  item->mNext = &this->m_items.mNode;
  this->m_items.mNode.mPrev = &item->UFG::qNode<UFG::UIItem,UFG::UIItem>;
  if ( !this->m_firstVisibleItem )
  {
    this->m_firstVisibleItem = item;
    this->m_firstVisibleItemIndex = 0;
  }
  if ( !this->m_selectedItem )
  {
    this->m_selectedItem = item;
    this->m_selectedItemIndex = 0;
  }
}

// File Line: 55
// RVA: 0x61DF50
void __fastcall UFG::UIWidget::addSlot(UFG::UIWidget *this, UFG::UISlot *slot)
{
  UFG::qNode<UFG::UISlot,UFG::UISlot> *mPrev; // rax
  UFG::qNode<UFG::UISlot,UFG::UISlot> *v3; // rdx
  UFG::qList<UFG::UISlot,UFG::UISlot,1,0> *p_m_slots; // rcx

  mPrev = this->m_slots.mNode.mPrev;
  v3 = &slot->UFG::qNode<UFG::UISlot,UFG::UISlot>;
  p_m_slots = &this->m_slots;
  mPrev->mNext = v3;
  v3->mPrev = mPrev;
  v3->mNext = &p_m_slots->mNode;
  p_m_slots->mNode.mPrev = v3;
}

