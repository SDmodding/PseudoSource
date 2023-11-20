// File Line: 47
// RVA: 0x4384D0
void __fastcall UFG::ResourcePriorityBucket::AddChild(UFG::ResourcePriorityBucket *this, UFG::ResourcePriorityBucket *child)
{
  __int64 v2; // r14
  UFG::ResourcePriorityBucket *v3; // rsi
  unsigned int v4; // edx
  unsigned int v5; // ebx
  UFG::ResourcePriorityBucket *v6; // rbp
  unsigned int v7; // edx
  UFG::ResourcePriorityBucket **v8; // rax

  v2 = this->mChildren.size;
  v3 = child;
  v4 = this->mChildren.capacity;
  v5 = v2 + 1;
  v6 = this;
  if ( (signed int)v2 + 1 > v4 )
  {
    if ( v4 )
      v7 = 2 * v4;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v5 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mChildren,
      v7,
      "ResourcePriorityBucket::mChildren");
  }
  v8 = v6->mChildren.p;
  v6->mChildren.size = v5;
  v8[v2] = v3;
  v3->mpParent = v6;
}

// File Line: 121
// RVA: 0x436C60
void __fastcall UFG::PreloadRequest::PreloadRequest(UFG::PreloadRequest *this)
{
  signed int v1; // edx
  UFG::qColour **v2; // rax

  this->mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&this->mPrev;
  v1 = 15;
  v2 = &this->mInstance.mPart[0].mColourTint;
  do
  {
    *(v2 - 1) = 0i64;
    *v2 = 0i64;
    v2 += 2;
    --v1;
  }
  while ( v1 >= 0 );
  this->mPriority.mUID = -1;
  this->mSpawnSetValid = 0;
  this->mPreloadActive = 0;
  this->mDirectRequestCount = 0;
  *(_QWORD *)&this->mDesiredInstanceCount = 0i64;
  this->mVarietyRatio = 0.0;
  this->mInstance.mSet = 0i64;
  this->mInstance.mNumParts = 0;
}

// File Line: 130
// RVA: 0x43DDE0
UFG::qSymbol *__fastcall UFG::PreloadRequest::GetPriority(UFG::PreloadRequest *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->mPriority;
  return result;
}

