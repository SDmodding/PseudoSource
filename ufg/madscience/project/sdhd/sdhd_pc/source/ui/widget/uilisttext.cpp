// File Line: 21
// RVA: 0x637990
void __fastcall UFG::UIListText::init(UFG::UIListText *this, UFG::UIList::UIListData *initData)
{
  UFG::UIList::UIListData *v2; // rsi
  UFG::UIListText *v3; // rdi
  int v4; // ebp
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx
  UFG::UIScreen *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qString result; // [rsp+38h] [rbp-40h]

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
  v4 = 0;
  while ( v4 < v2->m_numSlots )
  {
    UFG::qString::FormatEx(&result, "%s.menu_slot_%d", v2->m_pathToWidget.mData, (unsigned int)++v4);
    v5 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x58ui64, "UIListText::UISlotText", 0i64, 1u);
    v6 = v5;
    if ( v5 )
    {
      v7 = v3->m_screen;
      v8 = v5 + 1;
      v8->mNext = v8;
      v8[1].mNext = v8;
      v6->mNext = (UFG::allocator::free_link *)&UFG::UISlot::`vftable';
      v6[3].mNext = (UFG::allocator::free_link *)v7;
      UFG::qString::qString((UFG::qString *)&v6[4], &result);
      LOWORD(v6[10].mNext) = 0;
      v6->mNext = (UFG::allocator::free_link *)&UFG::UISlotText::`vftable';
    }
    else
    {
      v6 = 0i64;
    }
    (*(void (__fastcall **)(UFG::UIListText *, UFG::allocator::free_link *))v3->vfptr->gap8)(v3, v6);
    UFG::qString::~qString(&result);
  }
}

