// File Line: 178
// RVA: 0x197470
bool __fastcall UFG::DUIRect::Contains(UFG::DUIRect *this, UFG::DUIPoint *point)
{
  int mY; // edx
  int v3; // r8d
  bool result; // al

  result = 0;
  if ( point->mX >= this->mX && point->mX <= this->mW + this->mX )
  {
    mY = point->mY;
    v3 = this->mY;
    if ( mY >= v3 && mY <= this->mH + v3 - 1 )
      return 1;
  }
  return result;
}

// File Line: 183
// RVA: 0x1973F0
bool __fastcall UFG::DUIRect::Contains(UFG::DUIRect *this, UFG::DUIRect *rect)
{
  int mX; // r11d
  int v3; // ebx
  int mY; // r9d
  int v6; // edi
  int v7; // edx
  int v8; // r10d
  int v9; // r11d
  int v10; // ecx
  bool result; // al

  mX = rect->mX;
  v3 = this->mX;
  mY = rect->mY;
  result = 0;
  if ( rect->mX >= this->mX )
  {
    v6 = this->mW + v3;
    if ( mX <= v6 )
    {
      v7 = this->mY;
      if ( mY >= v7 )
      {
        v8 = this->mH + v7 - 1;
        if ( mY <= v8 )
        {
          v9 = rect->mW + mX;
          v10 = mY + rect->mH;
          if ( v9 >= v3 && v9 <= v6 && v10 >= v7 && v10 <= v8 )
            return 1;
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
  int mY; // r8d
  int v3; // r10d
  bool result; // al

  result = 0;
  if ( this->mX < rect->mX + rect->mW && this->mX + this->mW > rect->mX )
  {
    mY = rect->mY;
    v3 = this->mY;
    if ( v3 < mY + rect->mH && v3 + this->mH > mY )
      return 1;
  }
  return result;
}

// File Line: 195
// RVA: 0x19BE90
__int64 __fastcall UFG::DUIRect::OverlappedArea(UFG::DUIRect *this, UFG::DUIRect *rect)
{
  int mX; // edi
  int v3; // esi
  int v4; // ebp
  int mW; // r14d
  int mY; // r15d
  int v7; // r12d
  int v8; // r13d
  int mH; // ebx

  mX = rect->mX;
  v3 = this->mX;
  v4 = rect->mX + rect->mW;
  if ( this->mX >= v4 )
    return 0i64;
  mW = this->mW;
  if ( mW + v3 <= mX )
    return 0i64;
  mY = rect->mY;
  v7 = this->mY;
  v8 = mY + rect->mH;
  if ( v7 >= v8 )
    return 0i64;
  mH = this->mH;
  if ( mH + v7 <= mY )
    return 0i64;
  if ( UFG::DUIRect::Contains(this, rect) )
    return (unsigned int)(mW * mH);
  if ( v3 > mX )
    mX = v3;
  if ( v7 > mY )
    mY = v7;
  if ( mH + v7 < v8 )
    v8 = mH + v7;
  if ( mW + v3 < v4 )
    v4 = mW + v3;
  return (unsigned int)((v8 - mY) * (v4 - mX));
}

// File Line: 283
// RVA: 0x19A330
UFG::DUIRect *__fastcall UFG::DUIRect::Merge(UFG::DUIRect *this, UFG::DUIRect *rect)
{
  int mX; // ebx
  int v3; // r8d
  int mY; // r10d
  int mH; // edi
  int v6; // ebp
  int v7; // r11d
  int v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // r9d
  int v13; // ecx
  int v14; // eax
  int v15; // edi
  int v16; // r9d
  int v17; // ecx
  int v18; // eax

  mX = rect->mX;
  v3 = this->mX;
  mY = rect->mY;
  mH = rect->mH;
  v6 = rect->mX + rect->mW;
  v7 = this->mX + this->mW;
  v9 = v6;
  v10 = rect->mX;
  v11 = this->mY;
  v12 = this->mH;
  if ( this->mX < mX )
    v10 = this->mX;
  v13 = this->mX + this->mW;
  if ( v10 < v7 )
    v13 = v10;
  v14 = mY;
  if ( v13 < v6 )
    v9 = v13;
  v15 = mY + mH;
  v16 = v11 + v12;
  v17 = v16;
  this->mX = v9;
  if ( v11 < mY )
    v14 = v11;
  if ( v14 < v16 )
    v17 = v14;
  v18 = v15;
  if ( v17 < v15 )
    v18 = v17;
  if ( v3 > mX )
    mX = v3;
  this->mY = v18;
  if ( mX > v7 )
    v7 = mX;
  if ( v7 > v6 )
    v6 = v7;
  if ( v11 > mY )
    mY = v11;
  if ( mY > v16 )
    v16 = mY;
  if ( v16 > v15 )
    v15 = v16;
  this->mW = v6 - v9;
  this->mH = v15 - v18;
  return this;
}

// File Line: 612
// RVA: 0x1531A0
void __fastcall UFG::DUIWindow::DUIWindow(UFG::DUIWindow *this)
{
  UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>(this);
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>::mPrev = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>::mNext = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>::mPrev = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>::mNext = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>;
  UFG::qSafePointerNode<UFG::DUIWindow>::qSafePointerNode<UFG::DUIWindow>(&this->UFG::qSafePointerNode<UFG::DUIWindow>);
  this->UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  *(_QWORD *)&this->mGroupTag.mText.mData.mNumItems = 0i64;
  this->mGroupTag.mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mSurfaceName.mText.mData.mNumItems = 0i64;
  this->mSurfaceName.mText.mData.mItems = 0i64;
  UFG::qString::qString(&this->mTitle);
  UFG::DUIWindow::Init(this);
}

// File Line: 613
// RVA: 0x1530B0
void __fastcall UFG::DUIWindow::DUIWindow(UFG::DUIWindow *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::`vftable;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>::mPrev = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>::mNext = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>::mPrev = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>::mNext = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>;
  UFG::qSafePointerNode<UFG::DUIWindow>::qSafePointerNode<UFG::DUIWindow>(&this->UFG::qSafePointerNode<UFG::DUIWindow>);
  this->UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mGroupTag.mText.mData.mFlags = 2;
  this->mSurfaceName.mText.mData.mFlags = 2;
  UFG::qString::qString(&this->mTitle);
  UFG::DUIWindow::NoSerializeInit(this);
}

// File Line: 614
// RVA: 0x154DF0
void __fastcall UFG::DUIWindow::~DUIWindow(UFG::DUIWindow *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rsi
  UFG::qReflectString *p_mSurfaceName; // rbx
  UFG::qReflectString *p_mGroupTag; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v7; // rcx
  UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *v8; // rax
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *v9; // rcx
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *v10; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v11; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v12; // rax

  this->UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<UFG::DUIWindow>;
  this->UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::~qString(&this->mTitle);
  p_mSurfaceName = &this->mSurfaceName;
  if ( (this->mSurfaceName.mText.mData.mFlags & 2) == 0 )
    operator delete[](p_mSurfaceName->mText.mData.mItems);
  p_mSurfaceName->mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mSurfaceName.mText.mData.mNumItems = 0i64;
  p_mGroupTag = &this->mGroupTag;
  if ( (this->mGroupTag.mText.mData.mFlags & 2) == 0 )
    operator delete[](p_mGroupTag->mText.mData.mItems);
  p_mGroupTag->mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mGroupTag.mText.mData.mNumItems = 0i64;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::DUIWindow>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  mPrev = v2->m_SafePointerList.mNode.mPrev;
  mNext = v2->m_SafePointerList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  v7 = this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>::mPrev;
  v8 = this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>::mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>::mPrev = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>::mNext = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIManager>;
  v9 = this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>::mPrev;
  v10 = this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>::mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>::mPrev = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>;
  this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>::mNext = &this->UFG::qNode<UFG::DUIWindow,UFG::DUIWindow>;
  this->UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&this->mHandles);
  v11 = this->mHandles.mNode.UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::mPrev;
  v12 = this->mHandles.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  this->mHandles.mNode.UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
}

// File Line: 819
// RVA: 0x193A40
void __fastcall UFG::DUIIntArray::Add(UFG::DUIIntArray *this, unsigned __int64 item)
{
  __int64 size; // rsi
  UFG::qArray<unsigned __int64,0> *p_mData; // rdi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned __int64 *p; // rax

  size = this->mData.size;
  p_mData = &this->mData;
  capacity = this->mData.capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mData,
      v7,
      "qArray.Add");
  }
  p = p_mData->p;
  p_mData->size = v6;
  p[size] = item;
}

// File Line: 820
// RVA: 0x19CAA0
void __fastcall UFG::DUIIntArray::Remove(UFG::DUIIntArray *this, unsigned __int64 item)
{
  unsigned int size; // eax

  this->mData.p[this->vfptr->IndexOf(this, item)] = this->mData.p[this->mData.size - 1];
  size = this->mData.size;
  if ( size > 1 )
    this->mData.size = size - 1;
  else
    this->mData.size = 0;
}

// File Line: 821
// RVA: 0x19CAF0
void __fastcall UFG::DUIIntArray::RemoveAt(UFG::DUIIntArray *this, unsigned int idx)
{
  unsigned int size; // eax

  this->mData.p[idx] = this->mData.p[this->mData.size - 1];
  size = this->mData.size;
  if ( size > 1 )
    this->mData.size = size - 1;
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
__int64 __fastcall UFG::DUIIntArray::IndexOf(UFG::DUIIntArray *this, unsigned __int64 item)
{
  unsigned int size; // r8d
  __int64 result; // rax
  unsigned __int64 *i; // rcx

  size = this->mData.size;
  result = 0i64;
  if ( !size )
    return 0xFFFFFFFFi64;
  for ( i = this->mData.p; item != *i; ++i )
  {
    result = (unsigned int)(result + 1);
    if ( (unsigned int)result >= size )
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

