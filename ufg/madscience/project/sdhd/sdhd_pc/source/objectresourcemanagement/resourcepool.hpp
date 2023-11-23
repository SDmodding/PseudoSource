// File Line: 47
// RVA: 0x4384D0
void __fastcall UFG::ResourcePriorityBucket::AddChild(
        UFG::ResourcePriorityBucket *this,
        UFG::ResourcePriorityBucket *child)
{
  __int64 size; // r14
  unsigned int capacity; // edx
  unsigned int v5; // ebx
  unsigned int v7; // edx
  UFG::ResourcePriorityBucket **p; // rax

  size = this->mChildren.size;
  capacity = this->mChildren.capacity;
  v5 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v5 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mChildren,
      v7,
      "ResourcePriorityBucket::mChildren");
  }
  p = this->mChildren.p;
  this->mChildren.size = v5;
  p[size] = child;
  child->mpParent = this;
}

// File Line: 121
// RVA: 0x436C60
void __fastcall UFG::PreloadRequest::PreloadRequest(UFG::PreloadRequest *this)
{
  int v1; // edx
  UFG::qColour **p_mColourTint; // rax

  this->mPrev = this;
  this->mNext = this;
  v1 = 15;
  p_mColourTint = &this->mInstance.mPart[0].mColourTint;
  do
  {
    *(p_mColourTint - 1) = 0i64;
    *p_mColourTint = 0i64;
    p_mColourTint += 2;
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

