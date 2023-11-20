// File Line: 18
// RVA: 0x641920
void __fastcall UFG::UIWidget::update(UFG::UIWidget *this)
{
  UFG::UIItem *v1; // rdi
  UFG::qNode<UFG::UIItem,UFG::UIItem> **v2; // rbp
  UFG::UIWidget *v3; // rbx
  UFG::UIWidget *v4; // rsi
  UFG::UIWidgetVtbl *v5; // rax
  UFG::UIWidget *v6; // rcx

  v1 = this->m_firstVisibleItem;
  v2 = &this->m_items.mNode.mNext;
  v3 = (UFG::UIWidget *)&this->m_slots.mNode.mNext[-1].mNext;
  v4 = this;
  if ( v3 != (UFG::UIWidget *)&this->m_items.mNode.mNext )
  {
    do
    {
      v5 = v3->vfptr;
      if ( v1 )
        v5->update(v3);
      else
        ((void (__fastcall *)(UFG::UIWidget *))v5->handleMessage)(v3);
      (*(void (__fastcall **)(UFG::UIWidget *, UFG::UIItem *))v3->vfptr->gap8)(v3, v1);
      if ( v1 == v4->m_selectedItem )
      {
        v6 = (UFG::UIWidget *)v4->m_highlightedSlot;
        if ( v6 != v3 )
        {
          if ( v6 )
            ((void (*)(void))v6->vfptr->clear)();
          v4->m_highlightedSlot = (UFG::UISlot *)v3;
          ((void (__fastcall *)(UFG::UIWidget *))v3->vfptr->addItem)(v3);
        }
      }
      if ( v1 )
      {
        v1 = (UFG::UIItem *)&v1->mNext[-1].mNext;
        if ( v1 == (UFG::UIItem *)v4 )
          v1 = 0i64;
      }
      v3 = (UFG::UIWidget *)&v3->m_items.mNode.mNext[-1].mNext;
    }
    while ( v3 != (UFG::UIWidget *)v2 );
  }
}

// File Line: 57
// RVA: 0x63A9B0
void __fastcall UFG::UIWidget::setSelectedItemIndex(UFG::UIWidget *this, __int64 index, bool shouldSetFirstVisible)
{
  signed int v3; // er8
  int v4; // er10
  UFG::UIWidget *i; // rax
  UFG::UIItem *v6; // rax

  v3 = 0;
  v4 = index;
  for ( i = (UFG::UIWidget *)&this->m_items.mNode.mNext[-1].mNext;
        i != this;
        i = (UFG::UIWidget *)&i->m_items.mNode.mNext[-1].mNext )
  {
    ++v3;
  }
  if ( (signed int)index <= v3 )
  {
    v6 = (UFG::UIItem *)&this->m_items.mNode.mNext[-1].mNext;
    this->m_selectedItem = v6;
    if ( (signed int)index > 0 )
    {
      index = (unsigned int)index;
      do
      {
        v6 = (UFG::UIItem *)&v6->mNext[-1].mNext;
        this->m_selectedItem = v6;
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
  int v2; // er10
  UFG::UIWidget *v3; // r8
  int v4; // eax
  bool v5; // r9
  bool v6; // zf
  bool v7; // sf
  __int64 v8; // rdx
  UFG::UIItem *v9; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v10; // rcx

  v2 = index;
  v3 = this;
  v4 = index - this->m_firstVisibleItemIndex;
  v5 = index - this->m_firstVisibleItemIndex > 0;
  v6 = index == this->m_firstVisibleItemIndex;
  v7 = v4 < 0;
  if ( v4 < 0 )
  {
    v4 = this->m_firstVisibleItemIndex - index;
    v6 = this->m_firstVisibleItemIndex == index;
    v7 = v4 < 0;
  }
  if ( v7 || v6 )
  {
    this->m_firstVisibleItemIndex = index;
  }
  else
  {
    v8 = (unsigned int)v4;
    do
    {
      v9 = v3->m_firstVisibleItem;
      if ( v5 )
        v10 = v9->mNext;
      else
        v10 = v9->mPrev;
      v3->m_firstVisibleItem = (UFG::UIItem *)&v10[-1].mNext;
      --v8;
    }
    while ( v8 );
    v3->m_firstVisibleItemIndex = v2;
  }
}

// File Line: 95
// RVA: 0x61F300
void __fastcall UFG::UIWidget::clear(UFG::UIWidget *this)
{
  UFG::UIWidget *v1; // rbx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *i; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v3; // rcx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v4; // rdx

  v1 = this;
  ((void (*)(void))this->vfptr->reset)();
  for ( i = v1->m_items.mNode.mNext; &i[-1].mNext != (UFG::qNode<UFG::UIItem,UFG::UIItem> **)v1; i = v1->m_items.mNode.mNext )
  {
    v3 = i->mNext;
    v4 = i->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::UIItem,UFG::UIItem> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::UIItem,UFG::UIItem> **, signed __int64))i[-1].mNext->mPrev)(
        &i[-1].mNext,
        1i64);
  }
  v1->m_selectedItemIndex = -1;
  v1->m_firstVisibleItemIndex = -1;
  v1->m_selectedItem = 0i64;
  v1->m_firstVisibleItem = 0i64;
  v1->m_highlightedSlot = 0i64;
}

// File Line: 109
// RVA: 0x63A1D0
void __fastcall UFG::UIWidget::reset(UFG::UIWidget *this)
{
  UFG::UIWidget *v1; // rbx
  UFG::UIItem *v2; // rax
  UFG::UISlot *v3; // rcx

  v1 = this;
  v2 = (UFG::UIItem *)&this->m_items.mNode.mNext[-1].mNext;
  this->m_selectedItem = v2;
  this->m_firstVisibleItem = v2;
  this->m_selectedItemIndex = 0;
  this->m_firstVisibleItemIndex = 0;
  v3 = this->m_highlightedSlot;
  if ( v3 )
    ((void (*)(void))v3->vfptr->unhighlight)();
  v1->m_highlightedSlot = (UFG::UISlot *)&v1->m_slots.mNode.mNext[-1].mNext;
}

