// File Line: 172
// RVA: 0x6C2430
char __fastcall Scaleform::GFx::AS2::ArrayObject::Sort<Scaleform::GFx::AS2::ArraySortFunctor>(Scaleform::GFx::AS2::ArrayObject *this, Scaleform::GFx::AS2::ArraySortFunctor *sf)
{
  unsigned __int64 v2; // r8
  unsigned int v3; // ebx
  Scaleform::GFx::AS2::ArraySortFunctor *v4; // rax
  Scaleform::GFx::AS2::ArraySortFunctor *v5; // rdi
  Scaleform::GFx::AS2::ArraySortFunctor *v6; // rax
  Scaleform::GFx::AS2::Value **v8; // [rsp+20h] [rbp-98h]
  __int64 v9; // [rsp+28h] [rbp-90h]
  __int64 v10; // [rsp+30h] [rbp-88h]
  Scaleform::GFx::AS2::ArraySortFunctor v11; // [rsp+38h] [rbp-80h]
  Scaleform::GFx::AS2::ArraySortFunctor v12; // [rsp+70h] [rbp-48h]

  v10 = -2i64;
  v2 = this->Elements.Data.Size;
  if ( !v2 )
    return 1;
  v8 = this->Elements.Data.Data;
  v3 = v2;
  v9 = (unsigned int)v2;
  Scaleform::GFx::AS2::ArraySortFunctor::ArraySortFunctor(&v12, sf);
  v5 = v4;
  Scaleform::GFx::AS2::ArraySortFunctor::ArraySortFunctor(&v11, v4);
  LOBYTE(v3) = Scaleform::Alg::QuickSortSlicedSafe<Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *>,Scaleform::GFx::AS2::ArraySortFunctor>(
                 (Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *> *)&v8,
                 0i64,
                 v3,
                 v6);
  Scaleform::GFx::AS2::ArraySortFunctor::~ArraySortFunctor(v5);
  return v3;
}

