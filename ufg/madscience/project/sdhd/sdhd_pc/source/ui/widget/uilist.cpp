// File Line: 27
// RVA: 0x637920
void __fastcall UFG::UIList::init(UFG::UIList *this, UFG::UIList::UIListData *initData)
{
  UFG::UIList::UIListData *v2; // rdi
  UFG::UIList *v3; // rsi

  v2 = initData;
  v3 = this;
  UFG::qString::Set(
    &this->m_initData.m_pathToWidget,
    initData->m_pathToWidget.mData,
    initData->m_pathToWidget.mLength,
    0i64,
    0);
  v3->m_initData.m_numSlots = v2->m_numSlots;
  v3->m_initData.m_isVertical = v2->m_isVertical;
  v3->m_initData.m_canWrap = v2->m_canWrap;
  v3->vfptr->update((UFG::UIWidget *)&v3->vfptr);
}

// File Line: 39
// RVA: 0x641350
void __fastcall UFG::UIList::update(UFG::UIList *this)
{
  UFG::UIList *v1; // rdi
  char v2; // r14
  signed int v3; // ebx
  signed __int64 i; // rax
  char v5; // si
  UFG::qString *v6; // rax
  Scaleform::GFx::Movie *v7; // rbx
  UFG::qString v8; // [rsp+30h] [rbp-B8h]
  __int64 v9; // [rsp+58h] [rbp-90h]
  char v10; // [rsp+60h] [rbp-88h]
  __int64 v11; // [rsp+68h] [rbp-80h]
  __int64 v12; // [rsp+70h] [rbp-78h]
  unsigned int ptr; // [rsp+78h] [rbp-70h]
  __int64 v14; // [rsp+88h] [rbp-60h]
  unsigned int v15; // [rsp+90h] [rbp-58h]
  __int64 v16; // [rsp+98h] [rbp-50h]
  __int64 v17; // [rsp+A0h] [rbp-48h]
  char v18; // [rsp+A8h] [rbp-40h]
  __int64 v19; // [rsp+B8h] [rbp-30h]
  unsigned int v20; // [rsp+C0h] [rbp-28h]
  __int64 v21; // [rsp+C8h] [rbp-20h]
  __int64 v22; // [rsp+D0h] [rbp-18h]
  __int64 v23; // [rsp+D8h] [rbp-10h]
  UFG::qString result; // [rsp+E0h] [rbp-8h]

  v23 = -2i64;
  v1 = this;
  UFG::UIWidget::update((UFG::UIWidget *)&this->vfptr);
  v2 = 0;
  if ( v1->m_firstVisibleItemIndex > 0 )
    v2 = 1;
  v3 = 0;
  for ( i = (signed __int64)&v1->m_items.mNode.mNext[-1].mNext; (UFG::UIList *)i != v1; i = *(_QWORD *)(i + 16) - 8i64 )
    ++v3;
  v5 = 0;
  if ( (signed int)(v1->m_firstVisibleItemIndex
                  + (unsigned __int64)((__int64 (__fastcall *)(UFG::UIList *))v1->vfptr[1].addItem)(v1)) < v3 )
    v5 = 1;
  if ( v1->m_initData.m_pathToWidget.mLength > 0 )
  {
    UFG::qString::qString(&v8, ".setUpDownArrow");
    UFG::operator+(&result, &v1->m_initData.m_pathToWidget, v6);
    UFG::qString::~qString(&v8);
    v7 = v1->m_screen->mRenderable->m_movie.pObject;
    `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v12 = 0i64;
    ptr = 2;
    LOBYTE(v11) = v2;
    if ( (v15 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v14 + 16i64))(v14, &ptr, v16);
      v14 = 0i64;
    }
    v15 = ptr;
    v16 = v11;
    v17 = v12;
    if ( (ptr >> 6) & 1 )
    {
      v14 = v12;
      (*(void (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v12 + 8i64))(v12, &ptr);
    }
    if ( (ptr >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v12 + 16i64))(v12, &v10, v11);
      v12 = 0i64;
    }
    ptr = 0;
    *(_QWORD *)&v8.mMagic = 0i64;
    LODWORD(v8.mData) = 2;
    LOBYTE(v8.mStringHash32) = v5;
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
      v19 = 0i64;
    }
    v20 = (unsigned int)v8.mData;
    v21 = *(_QWORD *)&v8.mStringHash32;
    v22 = v9;
    if ( (LODWORD(v8.mData) >> 6) & 1 )
    {
      v19 = *(_QWORD *)&v8.mMagic;
      (*(void (__fastcall **)(_QWORD, char *))(**(_QWORD **)&v8.mMagic + 8i64))(*(_QWORD *)&v8.mMagic, &v18);
    }
    if ( (LODWORD(v8.mData) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v8.mMagic + 16i64))(
        *(_QWORD *)&v8.mMagic,
        &v8,
        *(_QWORD *)&v8.mStringHash32);
      *(_QWORD *)&v8.mMagic = 0i64;
    }
    LODWORD(v8.mData) = 0;
    Scaleform::GFx::Movie::Invoke(v7, result.mData, 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&result);
  }
}

// File Line: 71
// RVA: 0x62F150
char __fastcall UFG::UIList::handleMessage(UFG::UIList *this, UFG::UIMessage *msg)
{
  UFG::UIList *v2; // rbx
  UFG::UIItem *v3; // rcx
  UFG::UIMessage *v4; // rdi
  unsigned int v6; // eax

  v2 = this;
  v3 = this->m_selectedItem;
  v4 = msg;
  if ( v3 && ((unsigned __int8 (*)(void))v3->vfptr->handleMessage)() )
  {
    v2->vfptr->update((UFG::UIWidget *)&v2->vfptr);
    return 1;
  }
  v6 = v4->m_messageId;
  if ( v2->m_initData.m_isVertical )
  {
    if ( v6 != UI_HASH_DPAD_UP_PRESSED_30 && v6 != UI_HASH_THUMBSTICK_LEFT_UP_30 )
    {
      if ( v6 == UI_HASH_DPAD_DOWN_PRESSED_30 || v6 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
      {
        (*(void (__fastcall **)(UFG::UIList *, signed __int64))v2->vfptr[1].gap8)(v2, 1i64);
        return 1;
      }
      return 0;
    }
LABEL_10:
    (*(void (__fastcall **)(UFG::UIList *, signed __int64))v2->vfptr[1].gap8)(v2, 0xFFFFFFFFi64);
    return 1;
  }
  if ( v6 == UI_HASH_DPAD_LEFT_PRESSED_30 )
    goto LABEL_10;
  if ( v6 == UI_HASH_DPAD_RIGHT_PRESSED_30 )
  {
    (*(void (__fastcall **)(UFG::UIList *, signed __int64))v2->vfptr[1].gap8)(v2, 1i64);
    return 1;
  }
  return 0;
}

// File Line: 120
// RVA: 0x63A220
void __fastcall UFG::UIList::scroll(UFG::UIList *this, UFG::UIWidget::eScrollDir dir)
{
  UFG::UIList *v2; // rbx
  UFG::UIItem *v3; // rcx
  signed __int64 v4; // rax
  int i; // edi
  signed __int64 v6; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v7; // rax
  int v8; // ecx
  int v9; // er8
  int v10; // edx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v11; // rax
  signed __int64 j; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v13; // rax
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // edi

  v2 = this;
  v3 = this->m_selectedItem;
  if ( v3 )
  {
    v4 = (signed __int64)&v2->m_items.mNode.mNext[-1].mNext;
    for ( i = 0; (UFG::UIList *)v4 != v2; v4 = *(_QWORD *)(v4 + 16) - 8i64 )
      ++i;
    if ( dir != 1 )
    {
      if ( dir != -1 )
        goto LABEL_37;
      if ( v3 == (UFG::UIItem *)&v2->m_items.mNode.mNext[-1].mNext )
      {
        if ( v2->m_initData.m_canWrap )
        {
          v2->m_selectedItem = (UFG::UIItem *)&v2->m_items.mNode.mPrev[-1].mNext;
          v2->m_selectedItemIndex = i - 1;
        }
      }
      else
      {
        v13 = v3->mPrev;
        --v2->m_selectedItemIndex;
        v2->m_selectedItem = (UFG::UIItem *)&v13[-1].mNext;
      }
      if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      v14 = v2->m_firstVisibleItemIndex;
      v15 = v2->m_selectedItemIndex;
      if ( v14 > v15 )
      {
        v2->m_firstVisibleItemIndex = v14 - 1;
        v2->m_firstVisibleItem = (UFG::UIItem *)&v2->m_firstVisibleItem->mPrev[-1].mNext;
        goto LABEL_37;
      }
      if ( !v2->m_initData.m_canWrap )
        goto LABEL_37;
      if ( v14 )
        goto LABEL_37;
      if ( v15 != i - 1 )
        goto LABEL_37;
      v16 = v2->m_initData.m_numSlots;
      if ( v16 >= i )
        goto LABEL_37;
      v17 = i - v16;
      v2->m_firstVisibleItemIndex = v17;
      for ( j = (signed __int64)&v2->m_items.mNode.mNext[-1].mNext; v17 > 0; j = *(_QWORD *)(j + 16) - 8i64 )
      {
        if ( (UFG::UIList *)j == v2 )
          break;
        --v17;
      }
      goto LABEL_36;
    }
    v6 = (signed __int64)&v3->mNext[-1].mNext;
    if ( (UFG::UIList *)v6 == v2 )
    {
      if ( !v2->m_initData.m_canWrap )
        goto LABEL_10;
      v7 = v2->m_items.mNode.mNext;
      v2->m_selectedItemIndex = 0;
      v6 = (signed __int64)&v7[-1].mNext;
    }
    else
    {
      ++v2->m_selectedItemIndex;
    }
    v2->m_selectedItem = (UFG::UIItem *)v6;
LABEL_10:
    if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    v8 = v2->m_initData.m_numSlots;
    v9 = v2->m_firstVisibleItemIndex;
    v10 = v2->m_selectedItemIndex;
    if ( v9 + v8 <= v10 )
    {
      v2->m_firstVisibleItemIndex = v9 + 1;
      v2->m_firstVisibleItem = (UFG::UIItem *)&v2->m_firstVisibleItem->mNext[-1].mNext;
LABEL_37:
      v2->vfptr->update((UFG::UIWidget *)&v2->vfptr);
      return;
    }
    if ( !v2->m_initData.m_canWrap || v10 || v8 >= i )
      goto LABEL_37;
    v11 = v2->m_items.mNode.mNext;
    v2->m_firstVisibleItemIndex = 0;
    j = (signed __int64)&v11[-1].mNext;
LABEL_36:
    v2->m_firstVisibleItem = (UFG::UIItem *)j;
    goto LABEL_37;
  }
}

