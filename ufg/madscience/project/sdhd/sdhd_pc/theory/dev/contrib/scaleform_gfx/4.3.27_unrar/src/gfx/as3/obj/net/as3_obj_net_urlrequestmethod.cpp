// File Line: 41
// RVA: 0x783AA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_net::URLRequestMethod::URLRequestMethod(Scaleform::GFx::AS3::Classes::fl_net::URLRequestMethod *this, Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Classes::fl_net::URLRequestMethod *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Class::Class((Scaleform::GFx::AS3::Class *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_net::URLRequestMethod::`vftable';
  v2->DELETE = "DELETE";
  v2->GET = "GET";
  v2->HEAD = "HEAD";
  v2->OPTIONS = "OPTIONS";
  v2->POST = "POST";
  v2->PUT = "PUT";
}

// File Line: 72
// RVA: 0x750940
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_net::URLRequestMethod::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Classes::fl_net::URLRequestMethod *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_net::URLRequestMethodCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_net::URLRequestMethod::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_net::URLRequestMethodCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl_net::URLRequestMethod *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                                                   v4,
                                                                   120i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl_net::URLRequestMethod::URLRequestMethod(v9, v3->pV);
  return v3;
}

