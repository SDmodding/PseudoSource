// File Line: 159
// RVA: 0x156150
void __fastcall UFG::PartPool::Bucket::AddChild(UFG::PartPool::Bucket *this, UFG::PartPool::Bucket *child)
{
  __int64 v2; // r14
  UFG::PartPool::Bucket *v3; // rsi
  unsigned int v4; // edx
  unsigned int v5; // ebx
  UFG::PartPool::Bucket *v6; // rbp
  unsigned int v7; // edx
  UFG::PartPool::Bucket **v8; // rax

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
      "Bucket::mChildren");
  }
  v8 = v6->mChildren.p;
  v6->mChildren.size = v5;
  v8[v2] = v3;
  v3->mParent = v6;
}

