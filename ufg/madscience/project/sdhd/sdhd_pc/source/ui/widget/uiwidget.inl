// File Line: 25
// RVA: 0x5CE7E0
void __fastcall UFG::UIWidget::~UIWidget(UFG::UIWidget *this)
{
  UFG::UIWidget *v1; // rdi
  UFG::qList<UFG::UISlot,UFG::UISlot,1,0> *v2; // rbx
  UFG::qNode<UFG::UISlot,UFG::UISlot> *v3; // rcx
  UFG::qNode<UFG::UISlot,UFG::UISlot> *v4; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v5; // rcx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::UIWidgetVtbl *)&UFG::UIWidget::`vftable';
  v2 = &this->m_slots;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_slots);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_items);
  v5 = v1->m_items.mNode.mPrev;
  v6 = v1->m_items.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->m_items.mNode.mPrev = &v1->m_items.mNode;
  v1->m_items.mNode.mNext = &v1->m_items.mNode;
}

// File Line: 34
// RVA: 0x61DF10
void __fastcall UFG::UIWidget::addItem(UFG::UIWidget *this, UFG::UIItem *item)
{
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v2; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v3; // r8

  v2 = this->m_items.mNode.mPrev;
  v3 = (UFG::qNode<UFG::UIItem,UFG::UIItem> *)&item->mPrev;
  v2->mNext = (UFG::qNode<UFG::UIItem,UFG::UIItem> *)&item->mPrev;
  v3->mPrev = v2;
  v3->mNext = &this->m_items.mNode;
  this->m_items.mNode.mPrev = (UFG::qNode<UFG::UIItem,UFG::UIItem> *)&item->mPrev;
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
  UFG::qNode<UFG::UISlot,UFG::UISlot> *v2; // rax
  UFG::qNode<UFG::UISlot,UFG::UISlot> *v3; // rdx
  UFG::qList<UFG::UISlot,UFG::UISlot,1,0> *v4; // rcx

  v2 = this->m_slots.mNode.mPrev;
  v3 = (UFG::qNode<UFG::UISlot,UFG::UISlot> *)&slot->mPrev;
  v4 = &this->m_slots;
  v2->mNext = v3;
  v3->mPrev = v2;
  v3->mNext = &v4->mNode;
  v4->mNode.mPrev = v3;
}

