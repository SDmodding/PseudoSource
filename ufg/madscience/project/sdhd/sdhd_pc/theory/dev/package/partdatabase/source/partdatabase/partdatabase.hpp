// File Line: 159
// RVA: 0x156150
void __fastcall UFG::PartPool::Bucket::AddChild(UFG::PartPool::Bucket *this, UFG::PartPool::Bucket *child)
{
  __int64 size; // r14
  unsigned int capacity; // edx
  unsigned int v5; // ebx
  unsigned int v7; // edx
  UFG::PartPool::Bucket **p; // rax

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
      "Bucket::mChildren");
  }
  p = this->mChildren.p;
  this->mChildren.size = v5;
  p[size] = child;
  child->mParent = this;
}

