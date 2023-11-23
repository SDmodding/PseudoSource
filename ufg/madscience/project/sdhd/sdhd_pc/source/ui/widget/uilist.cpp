// File Line: 27
// RVA: 0x637920
void __fastcall UFG::UIList::init(UFG::UIList *this, UFG::UIList::UIListData *initData)
{
  UFG::qString::Set(
    &this->m_initData.m_pathToWidget,
    initData->m_pathToWidget.mData,
    initData->m_pathToWidget.mLength,
    0i64,
    0);
  this->m_initData.m_numSlots = initData->m_numSlots;
  this->m_initData.m_isVertical = initData->m_isVertical;
  this->m_initData.m_canWrap = initData->m_canWrap;
  this->vfptr->update(this);
}

// File Line: 39
// RVA: 0x641350
void __fastcall UFG::UIList::update(UFG::UIList *this)
{
  bool v2; // r14
  int v3; // ebx
  UFG::UIList *i; // rax
  bool v5; // si
  UFG::qString *v6; // rax
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::qString v8; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v9; // [rsp+58h] [rbp-90h]
  char v10[8]; // [rsp+60h] [rbp-88h] BYREF
  Scaleform::GFx::Value::ValueUnion v11; // [rsp+68h] [rbp-80h]
  Scaleform::GFx::Value::ObjectInterface *v12; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::Value ptr; // [rsp+78h] [rbp-70h] BYREF
  char v14[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v15; // [rsp+B8h] [rbp-30h]
  int mData; // [rsp+C0h] [rbp-28h]
  __int64 v17; // [rsp+C8h] [rbp-20h]
  __int64 v18; // [rsp+D0h] [rbp-18h]
  __int64 v19; // [rsp+D8h] [rbp-10h]
  UFG::qString result; // [rsp+E0h] [rbp-8h] BYREF

  v19 = -2i64;
  UFG::UIWidget::update(this);
  v2 = this->m_firstVisibleItemIndex > 0;
  v3 = 0;
  for ( i = (UFG::UIList *)&this->m_items.mNode.mNext[-1].mNext;
        i != this;
        i = (UFG::UIList *)&i->m_items.mNode.mNext[-1].mNext )
  {
    ++v3;
  }
  v5 = (int)(this->m_firstVisibleItemIndex + ((__int64 (__fastcall *)(UFG::UIList *))this->vfptr[1].addItem)(this)) < v3;
  if ( this->m_initData.m_pathToWidget.mLength > 0 )
  {
    UFG::qString::qString(&v8, ".setUpDownArrow");
    UFG::operator+(&result, &this->m_initData.m_pathToWidget, v6);
    UFG::qString::~qString(&v8);
    pObject = this->m_screen->mRenderable->m_movie.pObject;
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v12 = 0i64;
    LODWORD(ptr.pPrev) = 2;
    v11.BValue = v2;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = (Scaleform::GFx::Value::ValueType)ptr.pPrev;
    ptr.mValue = v11;
    ptr.DataAux = (unsigned __int64)v12;
    if ( ((__int64)ptr.pPrev & 0x40) != 0 )
    {
      ptr.pObjectInterface = v12;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *))v12->vfptr->gap8)(
        v12,
        &ptr);
    }
    if ( ((__int64)ptr.pPrev & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, char *, Scaleform::GFx::Value::ValueUnion))&v12->vfptr->gap8[8])(
        v12,
        v10,
        v11);
      v12 = 0i64;
    }
    LODWORD(ptr.pPrev) = 0;
    *(_QWORD *)&v8.mMagic = 0i64;
    LODWORD(v8.mData) = 2;
    LOBYTE(v8.mStringHash32) = v5;
    if ( (mData & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, v14, v17);
      v15 = 0i64;
    }
    mData = (int)v8.mData;
    v17 = *(_QWORD *)&v8.mStringHash32;
    v18 = v9;
    if ( ((__int64)v8.mData & 0x40) != 0 )
    {
      v15 = *(_QWORD *)&v8.mMagic;
      (*(void (__fastcall **)(_QWORD, char *))(**(_QWORD **)&v8.mMagic + 8i64))(*(_QWORD *)&v8.mMagic, v14);
    }
    if ( ((__int64)v8.mData & 0x40) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v8.mMagic + 16i64))(
        *(_QWORD *)&v8.mMagic,
        &v8,
        *(_QWORD *)&v8.mStringHash32);
      *(_QWORD *)&v8.mMagic = 0i64;
    }
    LODWORD(v8.mData) = 0;
    Scaleform::GFx::Movie::Invoke(pObject, result.mData, 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&result);
  }
}

// File Line: 71
// RVA: 0x62F150
char __fastcall UFG::UIList::handleMessage(UFG::UIList *this, UFG::UIMessage *msg)
{
  UFG::UIItem *m_selectedItem; // rcx
  unsigned int m_messageId; // eax

  m_selectedItem = this->m_selectedItem;
  if ( m_selectedItem
    && ((unsigned __int8 (__fastcall *)(UFG::UIItem *))m_selectedItem->vfptr->handleMessage)(m_selectedItem) )
  {
    this->vfptr->update(this);
    return 1;
  }
  m_messageId = msg->m_messageId;
  if ( this->m_initData.m_isVertical )
  {
    if ( m_messageId != UI_HASH_DPAD_UP_PRESSED_30 && m_messageId != UI_HASH_THUMBSTICK_LEFT_UP_30 )
    {
      if ( m_messageId == UI_HASH_DPAD_DOWN_PRESSED_30 || m_messageId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
        goto LABEL_13;
      return 0;
    }
LABEL_10:
    (*(void (__fastcall **)(UFG::UIList *, __int64))this->vfptr[1].gap8)(this, 0xFFFFFFFFi64);
    return 1;
  }
  if ( m_messageId == UI_HASH_DPAD_LEFT_PRESSED_30 )
    goto LABEL_10;
  if ( m_messageId == UI_HASH_DPAD_RIGHT_PRESSED_30 )
  {
LABEL_13:
    (*(void (__fastcall **)(UFG::UIList *, __int64))this->vfptr[1].gap8)(this, 1i64);
    return 1;
  }
  return 0;
}

// File Line: 120
// RVA: 0x63A220
void __fastcall UFG::UIList::scroll(UFG::UIList *this, UFG::UIWidget::eScrollDir dir)
{
  UFG::qNode<UFG::UIItem,UFG::UIItem> *m_selectedItem; // rcx
  UFG::UIList *p_mNext; // rax
  int i; // edi
  UFG::UIList *v6; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v7; // rax
  int v8; // ecx
  int v9; // r8d
  int v10; // edx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v11; // rax
  UFG::UIList *j; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *mNext; // rax
  int m_firstVisibleItemIndex; // eax
  int m_selectedItemIndex; // ecx
  int m_numSlots; // eax
  int v17; // edi

  m_selectedItem = (UFG::qNode<UFG::UIItem,UFG::UIItem> *)this->m_selectedItem;
  if ( m_selectedItem )
  {
    p_mNext = (UFG::UIList *)&this->m_items.mNode.mNext[-1].mNext;
    for ( i = 0; p_mNext != this; p_mNext = (UFG::UIList *)&p_mNext->m_items.mNode.mNext[-1].mNext )
      ++i;
    if ( dir != eScroll_Forward )
    {
      if ( dir != eScroll_Backward )
        goto LABEL_37;
      if ( m_selectedItem == (UFG::qNode<UFG::UIItem,UFG::UIItem> *)((char *)this->m_items.mNode.mNext - 8) )
      {
        if ( this->m_initData.m_canWrap )
        {
          this->m_selectedItem = (UFG::UIItem *)&this->m_items.mNode.mPrev[-1].mNext;
          this->m_selectedItemIndex = i - 1;
        }
      }
      else
      {
        mNext = m_selectedItem->mNext;
        --this->m_selectedItemIndex;
        this->m_selectedItem = (UFG::UIItem *)&mNext[-1].mNext;
      }
      if ( UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      m_firstVisibleItemIndex = this->m_firstVisibleItemIndex;
      m_selectedItemIndex = this->m_selectedItemIndex;
      if ( m_firstVisibleItemIndex > m_selectedItemIndex )
      {
        this->m_firstVisibleItemIndex = m_firstVisibleItemIndex - 1;
        this->m_firstVisibleItem = (UFG::UIItem *)&this->m_firstVisibleItem->mPrev[-1].mNext;
        goto LABEL_37;
      }
      if ( !this->m_initData.m_canWrap )
        goto LABEL_37;
      if ( m_firstVisibleItemIndex )
        goto LABEL_37;
      if ( m_selectedItemIndex != i - 1 )
        goto LABEL_37;
      m_numSlots = this->m_initData.m_numSlots;
      if ( m_numSlots >= i )
        goto LABEL_37;
      v17 = i - m_numSlots;
      this->m_firstVisibleItemIndex = v17;
      for ( j = (UFG::UIList *)&this->m_items.mNode.mNext[-1].mNext;
            v17 > 0;
            j = (UFG::UIList *)&j->m_items.mNode.mNext[-1].mNext )
      {
        if ( j == this )
          break;
        --v17;
      }
      goto LABEL_36;
    }
    v6 = (UFG::UIList *)&m_selectedItem[1].mPrev[-1].mNext;
    if ( v6 == this )
    {
      if ( !this->m_initData.m_canWrap )
        goto LABEL_10;
      v7 = this->m_items.mNode.mNext;
      this->m_selectedItemIndex = 0;
      v6 = (UFG::UIList *)&v7[-1].mNext;
    }
    else
    {
      ++this->m_selectedItemIndex;
    }
    this->m_selectedItem = (UFG::UIItem *)v6;
LABEL_10:
    if ( UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    v8 = this->m_initData.m_numSlots;
    v9 = this->m_firstVisibleItemIndex;
    v10 = this->m_selectedItemIndex;
    if ( v9 + v8 <= v10 )
    {
      this->m_firstVisibleItemIndex = v9 + 1;
      this->m_firstVisibleItem = (UFG::UIItem *)&this->m_firstVisibleItem->mNext[-1].mNext;
LABEL_37:
      this->vfptr->update(this);
      return;
    }
    if ( !this->m_initData.m_canWrap || v10 || v8 >= i )
      goto LABEL_37;
    v11 = this->m_items.mNode.mNext;
    this->m_firstVisibleItemIndex = 0;
    j = (UFG::UIList *)&v11[-1].mNext;
LABEL_36:
    this->m_firstVisibleItem = (UFG::UIItem *)j;
    goto LABEL_37;
  }
}

