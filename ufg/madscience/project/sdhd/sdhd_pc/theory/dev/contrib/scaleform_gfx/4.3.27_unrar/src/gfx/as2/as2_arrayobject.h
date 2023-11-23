// File Line: 172
// RVA: 0x6C2430
char __fastcall Scaleform::GFx::AS2::ArrayObject::Sort<Scaleform::GFx::AS2::ArraySortFunctor>(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ArraySortFunctor *sf)
{
  unsigned __int64 Size; // r8
  unsigned int v3; // ebx
  Scaleform::GFx::AS2::ArraySortFunctor *v4; // rax
  Scaleform::GFx::AS2::ArraySortFunctor *v5; // rdi
  Scaleform::GFx::AS2::ArraySortFunctor *v6; // rax
  Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *> v8; // [rsp+20h] [rbp-98h] BYREF
  __int64 v9; // [rsp+30h] [rbp-88h]
  Scaleform::GFx::AS2::ArraySortFunctor v10; // [rsp+38h] [rbp-80h] BYREF
  Scaleform::GFx::AS2::ArraySortFunctor v11; // [rsp+70h] [rbp-48h] BYREF

  v9 = -2i64;
  Size = this->Elements.Data.Size;
  if ( !Size )
    return 1;
  v8.Data = this->Elements.Data.Data;
  v3 = Size;
  v8.Size = (unsigned int)Size;
  Scaleform::GFx::AS2::ArraySortFunctor::ArraySortFunctor(&v11, sf);
  v5 = v4;
  Scaleform::GFx::AS2::ArraySortFunctor::ArraySortFunctor(&v10, v4);
  LOBYTE(v3) = Scaleform::Alg::QuickSortSlicedSafe<Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *>,Scaleform::GFx::AS2::ArraySortFunctor>(
                 &v8,
                 0i64,
                 v3,
                 v6);
  Scaleform::GFx::AS2::ArraySortFunctor::~ArraySortFunctor(v5);
  return v3;
}

