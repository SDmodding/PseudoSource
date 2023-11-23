// File Line: 18
// RVA: 0x641920
void __fastcall UFG::UIWidget::update(UFG::UIWidget *this)
{
  UFG::UIItem *m_firstVisibleItem; // rdi
  UFG::qNode<UFG::UIItem,UFG::UIItem> **p_mNext; // rbp
  UFG::UISlot *v3; // rbx
  UFG::UISlotVtbl *vfptr; // rax
  UFG::UISlot *m_highlightedSlot; // rcx

  m_firstVisibleItem = this->m_firstVisibleItem;
  p_mNext = &this->m_items.mNode.mNext;
  v3 = (UFG::UISlot *)&this->m_slots.mNode.mNext[-1].mNext;
  if ( v3 != (UFG::UISlot *)&this->m_items.mNode.mNext )
  {
    do
    {
      vfptr = v3->vfptr;
      if ( m_firstVisibleItem )
        vfptr->show(v3);
      else
        vfptr->hide(v3);
      v3->vfptr->update(v3, m_firstVisibleItem);
      if ( m_firstVisibleItem == this->m_selectedItem )
      {
        m_highlightedSlot = this->m_highlightedSlot;
        if ( m_highlightedSlot != v3 )
        {
          if ( m_highlightedSlot )
            m_highlightedSlot->vfptr->unhighlight(m_highlightedSlot);
          this->m_highlightedSlot = v3;
          v3->vfptr->highlight(v3);
        }
      }
      if ( m_firstVisibleItem )
      {
        m_firstVisibleItem = (UFG::UIItem *)&m_firstVisibleItem->mNext[-1].mNext;
        if ( m_firstVisibleItem == (UFG::UIItem *)this )
          m_firstVisibleItem = 0i64;
      }
      v3 = (UFG::UISlot *)&v3->mNext[-1].mNext;
    }
    while ( v3 != (UFG::UISlot *)p_mNext );
  }
}

// File Line: 57
// RVA: 0x63A9B0
void __fastcall UFG::UIWidget::setSelectedItemIndex(UFG::UIWidget *this, __int64 index, bool shouldSetFirstVisible)
{
  int v3; // r8d
  int v4; // r10d
  UFG::UIWidget *i; // rax
  UFG::UIItem *p_mNext; // rax

  v3 = 0;
  v4 = index;
  for ( i = (UFG::UIWidget *)&this->m_items.mNode.mNext[-1].mNext;
        i != this;
        i = (UFG::UIWidget *)&i->m_items.mNode.mNext[-1].mNext )
  {
    ++v3;
  }
  if ( (int)index <= v3 )
  {
    p_mNext = (UFG::UIItem *)&this->m_items.mNode.mNext[-1].mNext;
    this->m_selectedItem = p_mNext;
    if ( (int)index > 0 )
    {
      index = (unsigned int)index;
      do
      {
        p_mNext = (UFG::UIItem *)&p_mNext->mNext[-1].mNext;
        this->m_selectedItem = p_mNext;
        --index;
      }
      while ( index );
    }
    this->m_selectedItemIndex = v4;
  }
}

// File Line: 76
// RVA: 0x63A770
void __fastcall UFG::UIWidget::setFirstVisibleItemIndex(UFG::UIWidget *this, int index)
{
  int v4; // eax
  bool v5; // r9
  bool v6; // cc
  __int64 v7; // rdx
  UFG::UIItem *m_firstVisibleItem; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *mNext; // rcx

  v4 = index - this->m_firstVisibleItemIndex;
  v5 = v4 > 0;
  v6 = v4 <= 0;
  if ( v4 < 0 )
  {
    v4 = this->m_firstVisibleItemIndex - index;
    v6 = v4 <= 0;
  }
  if ( v6 )
  {
    this->m_firstVisibleItemIndex = index;
  }
  else
  {
    v7 = (unsigned int)v4;
    do
    {
      m_firstVisibleItem = this->m_firstVisibleItem;
      if ( v5 )
        mNext = m_firstVisibleItem->mNext;
      else
        mNext = m_firstVisibleItem->mPrev;
      this->m_firstVisibleItem = (UFG::UIItem *)&mNext[-1].mNext;
      --v7;
    }
    while ( v7 );
    this->m_firstVisibleItemIndex = index;
  }
}

// File Line: 95
// RVA: 0x61F300
void __fastcall UFG::UIWidget::clear(UFG::UIWidget *this)
{
  UFG::qNode<UFG::UIItem,UFG::UIItem> *i; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *mNext; // rcx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *mPrev; // rdx

  this->vfptr->reset(this);
  for ( i = this->m_items.mNode.mNext;
        &i[-1].mNext != (UFG::qNode<UFG::UIItem,UFG::UIItem> **)this;
        i = this->m_items.mNode.mNext )
  {
    mNext = i->mNext;
    mPrev = i->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::UIItem,UFG::UIItem> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::UIItem,UFG::UIItem> **, __int64))i[-1].mNext->mPrev)(&i[-1].mNext, 1i64);
  }
  this->m_selectedItemIndex = -1;
  this->m_firstVisibleItemIndex = -1;
  this->m_selectedItem = 0i64;
  this->m_firstVisibleItem = 0i64;
  this->m_highlightedSlot = 0i64;
}

// File Line: 109
// RVA: 0x63A1D0
void __fastcall UFG::UIWidget::reset(UFG::UIWidget *this)
{
  UFG::UIItem *p_mNext; // rax
  UFG::UISlot *m_highlightedSlot; // rcx

  p_mNext = (UFG::UIItem *)&this->m_items.mNode.mNext[-1].mNext;
  this->m_selectedItem = p_mNext;
  this->m_firstVisibleItem = p_mNext;
  this->m_selectedItemIndex = 0;
  this->m_firstVisibleItemIndex = 0;
  m_highlightedSlot = this->m_highlightedSlot;
  if ( m_highlightedSlot )
    m_highlightedSlot->vfptr->unhighlight(m_highlightedSlot);
  this->m_highlightedSlot = (UFG::UISlot *)&this->m_slots.mNode.mNext[-1].mNext;
}

