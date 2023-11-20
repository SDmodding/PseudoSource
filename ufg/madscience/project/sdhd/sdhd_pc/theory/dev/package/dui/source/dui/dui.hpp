// File Line: 178
// RVA: 0x197470
bool __fastcall UFG::DUIRect::Contains(UFG::DUIRect *this, UFG::DUIPoint *point)
{
  int v2; // edx
  int v3; // er8
  bool result; // al

  result = 0;
  if ( point->mX >= this->mX && point->mX <= this->mW + this->mX )
  {
    v2 = point->mY;
    v3 = this->mY;
    if ( v2 >= v3 && v2 <= this->mH + v3 - 1 )
      result = 1;
  }
  return result;
}

// File Line: 183
// RVA: 0x1973F0
bool __fastcall UFG::DUIRect::Contains(UFG::DUIRect *this, UFG::DUIRect *rect)
{
  int v2; // er11
  int v3; // ebx
  int v4; // er9
  UFG::DUIRect *v5; // r8
  int v6; // edi
  int v7; // edx
  int v8; // er10
  int v9; // er11
  int v10; // ecx
  bool result; // al

  v2 = rect->mX;
  v3 = this->mX;
  v4 = rect->mY;
  v5 = rect;
  result = 0;
  if ( rect->mX >= this->mX )
  {
    v6 = this->mW + v3;
    if ( v2 <= v6 )
    {
      v7 = this->mY;
      if ( v4 >= v7 )
      {
        v8 = this->mH + v7 - 1;
        if ( v4 <= v8 )
        {
          v9 = v5->mW + v2;
          v10 = v4 + v5->mH;
          if ( v9 >= v3 && v9 <= v6 && v10 >= v7 && v10 <= v8 )
            result = 1;
        }
      }
    }
  }
  return result;
}

// File Line: 189
// RVA: 0x19BF50
bool __fastcall UFG::DUIRect::Overlaps(UFG::DUIRect *this, UFG::DUIRect *rect)
{
  int v2; // er8
  int v3; // er10
  bool result; // al

  result = 0;
  if ( this->mX < rect->mX + rect->mW && this->mX + this->mW > rect->mX )
  {
    v2 = rect->mY;
    v3 = this->mY;
    if ( v3 < v2 + rect->mH && v3 + this->mH > v2 )
      result = 1;
  }
  return result;
}

// File Line: 195
// RVA: 0x19BE90
__int64 __fastcall UFG::DUIRect::OverlappedArea(UFG::DUIRect *this, UFG::DUIRect *rect)
{
  int v2; // edi
  int v3; // esi
  int v4; // ebp
  int v5; // er14
  int v6; // er15
  int v7; // er12
  int v8; // er13
  int v9; // ebx

  v2 = rect->mX;
  v3 = this->mX;
  v4 = rect->mX + rect->mW;
  if ( this->mX >= v4 )
    return 0i64;
  v5 = this->mW;
  if ( v5 + v3 <= v2 )
    return 0i64;
  v6 = rect->mY;
  v7 = this->mY;
  v8 = v6 + rect->mH;
  if ( v7 >= v8 )
    return 0i64;
  v9 = this->mH;
  if ( v9 + v7 <= v6 )
    return 0i64;
  if ( UFG::DUIRect::Contains(this, rect) )
    return (unsigned int)(v5 * v9);
  if ( v3 > v2 )
    v2 = v3;
  if ( v7 > v6 )
    v6 = v7;
  if ( v9 + v7 < v8 )
    v8 = v9 + v7;
  if ( v5 + v3 < v4 )
    v4 = v5 + v3;
  return (unsigned int)((v8 - v6) * (v4 - v2));
}

// File Line: 283
// RVA: 0x19A330
UFG::DUIRect *__fastcall UFG::DUIRect::Merge(UFG::DUIRect *this, UFG::DUIRect *rect)
{
  int v2; // ebx
  int v3; // er8
  int v4; // er10
  int v5; // edi
  int v6; // ebp
  int v7; // er11
  UFG::DUIRect *v8; // r14
  int v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // er9
  int v13; // ecx
  int v14; // eax
  int v15; // edi
  int v16; // er9
  int v17; // ecx
  int v18; // eax

  v2 = rect->mX;
  v3 = this->mX;
  v4 = rect->mY;
  v5 = rect->mH;
  v6 = rect->mX + rect->mW;
  v7 = this->mX + this->mW;
  v8 = this;
  v9 = rect->mX + rect->mW;
  v10 = rect->mX;
  v11 = this->mY;
  v12 = this->mH;
  if ( this->mX < v2 )
    v10 = this->mX;
  v13 = this->mX + this->mW;
  if ( v10 < v7 )
    v13 = v10;
  v14 = v4;
  if ( v13 < v6 )
    v9 = v13;
  v15 = v4 + v5;
  v16 = v11 + v12;
  v17 = v16;
  v8->mX = v9;
  if ( v11 < v4 )
    v14 = v11;
  if ( v14 < v16 )
    v17 = v14;
  v18 = v15;
  if ( v17 < v15 )
    v18 = v17;
  if ( v3 > v2 )
    v2 = v3;
  v8->mY = v18;
  if ( v2 > v7 )
    v7 = v2;
  if ( v7 > v6 )
    v6 = v7;
  if ( v11 > v4 )
    v4 = v11;
  if ( v4 > v16 )
    v16 = v4;
  if ( v16 > v15 )
    v15 = v16;
  v8->mW = v6 - v9;
  v8->mH = v15 - v18;
  return v8;
}

// File Line: 612
// RVA: 0x1531A0
void __fastcall UFG::DUIWindow::DUIWindow(UFG::DUIWindow *this)
{
  UFG::DUIWindow *v1; // rdi
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *v2; // rax
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v3; // rax
  UFG::qReflectString *v4; // [rsp+48h] [rbp+10h]
  UFG::qReflectString *v5; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>((UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject> *)&this->vfptr);
  v2 = (UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v3 = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  UFG::qSafePointerNode<UFG::DUIWindow>::qSafePointerNode<UFG::DUIWindow>((UFG::qSafePointerNode<UFG::DUIWindow> *)&v1->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIWindow::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIWindow::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v4 = &v1->mGroupTag;
  *(_QWORD *)&v4->mText.mData.mNumItems = 0i64;
  v4->mText.mData.mItems = 0i64;
  v5 = &v1->mSurfaceName;
  *(_QWORD *)&v5->mText.mData.mNumItems = 0i64;
  v5->mText.mData.mItems = 0i64;
  UFG::qString::qString(&v1->mTitle);
  UFG::DUIWindow::Init(v1);
}

// File Line: 613
// RVA: 0x1530B0
void __fastcall UFG::DUIWindow::DUIWindow(UFG::DUIWindow *this, MemImageLoadFlag f)
{
  UFG::DUIWindow *v2; // rdi
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *v5; // rax
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v6; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v7; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v7 = &this->mHandles;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::`vftable';
  v5 = (UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v6 = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  UFG::qSafePointerNode<UFG::DUIWindow>::qSafePointerNode<UFG::DUIWindow>((UFG::qSafePointerNode<UFG::DUIWindow> *)&this->vfptr);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIWindow::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIWindow::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->mGroupTag.mText.mData.mFlags = 2;
  v2->mSurfaceName.mText.mData.mFlags = 2;
  UFG::qString::qString(&v2->mTitle);
  UFG::DUIWindow::NoSerializeInit(v2);
}

// File Line: 614
// RVA: 0x154DF0
void __fastcall UFG::DUIWindow::~DUIWindow(UFG::DUIWindow *this)
{
  UFG::DUIWindow *v1; // rdi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rsi
  void **v3; // rbx
  void **v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v7; // rdx
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v8; // rcx
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v9; // rax
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *v10; // rdx
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *v11; // rcx
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *v12; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v13; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v14; // rax

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIWindow::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIWindow::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  UFG::qString::~qString(&this->mTitle);
  v3 = (void **)&v1->mSurfaceName.mText.mData.mItems;
  if ( !(v1->mSurfaceName.mText.mData.mFlags & 2) )
    operator delete[](*v3);
  *v3 = 0i64;
  *(_QWORD *)&v1->mSurfaceName.mText.mData.mNumItems = 0i64;
  v4 = (void **)&v1->mGroupTag.mText.mData.mItems;
  if ( !(v1->mGroupTag.mText.mData.mFlags & 2) )
    operator delete[](*v4);
  *v4 = 0i64;
  *(_QWORD *)&v1->mGroupTag.mText.mData.mNumItems = 0i64;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::DUIWindow>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v5 = v2->m_SafePointerList.mNode.mPrev;
  v6 = v2->m_SafePointerList.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  v7 = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
  v10 = (UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *)&v1->mPrev;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&v1->mHandles);
  v13 = v1->mHandles.mNode.mPrev;
  v14 = v1->mHandles.mNode.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v1->mHandles.mNode.mPrev = &v1->mHandles.mNode;
  v1->mHandles.mNode.mNext = &v1->mHandles.mNode;
}

// File Line: 819
// RVA: 0x193A40
void __fastcall UFG::DUIIntArray::Add(UFG::DUIIntArray *this, unsigned __int64 item)
{
  __int64 v2; // rsi
  UFG::qArray<unsigned __int64,0> *v3; // rdi
  unsigned __int64 v4; // rbp
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned __int64 *v8; // rax

  v2 = this->mData.size;
  v3 = &this->mData;
  v4 = item;
  v5 = this->mData.capacity;
  v6 = v2 + 1;
  if ( (signed int)v2 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mData,
      v7,
      "qArray.Add");
  }
  v8 = v3->p;
  v3->size = v6;
  v8[v2] = v4;
}

// File Line: 820
// RVA: 0x19CAA0
void __fastcall UFG::DUIIntArray::Remove(UFG::DUIIntArray *this, unsigned __int64 item)
{
  UFG::DUIIntArray *v2; // rbx
  unsigned int v3; // eax

  v2 = this;
  v2->mData.p[this->vfptr->IndexOf((UFG::IDUICollectionView *)this, item)] = v2->mData.p[v2->mData.size - 1];
  v3 = v2->mData.size;
  if ( v3 > 1 )
    v2->mData.size = v3 - 1;
  else
    v2->mData.size = 0;
}

// File Line: 821
// RVA: 0x19CAF0
void __fastcall UFG::DUIIntArray::RemoveAt(UFG::DUIIntArray *this, unsigned int idx)
{
  unsigned int v2; // eax

  this->mData.p[idx] = this->mData.p[this->mData.size - 1];
  v2 = this->mData.size;
  if ( v2 > 1 )
    this->mData.size = v2 - 1;
  else
    this->mData.size = 0;
}

// File Line: 822
// RVA: 0x198450
unsigned __int64 __fastcall UFG::DUIIntArray::GetAt(UFG::DUIIntArray *this, unsigned int idx)
{
  return this->mData.p[idx];
}

// File Line: 823
// RVA: 0x1993F0
signed __int64 __fastcall UFG::DUIIntArray::IndexOf(UFG::DUIIntArray *this, unsigned __int64 item)
{
  unsigned int v2; // er8
  signed __int64 result; // rax
  unsigned __int64 *v4; // rcx

  v2 = this->mData.size;
  result = 0i64;
  if ( !v2 )
    return 0xFFFFFFFFi64;
  v4 = this->mData.p;
  while ( item != *v4 )
  {
    result = (unsigned int)(result + 1);
    ++v4;
    if ( (unsigned int)result >= v2 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 824
// RVA: 0x195710
void __fastcall UFG::DUIIntArray::Clear(UFG::DUIIntArray *this)
{
  this->mData.size = 0;
}

