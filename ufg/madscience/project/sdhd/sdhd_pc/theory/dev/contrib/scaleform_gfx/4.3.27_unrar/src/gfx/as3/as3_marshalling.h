// File Line: 63
// RVA: 0x76C400
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>>(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result, Scaleform::GFx::AS3::StringManager *__formal)
{
  result->pObject = 0i64;
  return result;
}

// File Line: 152
// RVA: 0x76C430
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::ASString *v2; // rbx

  v2 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
    result);
  return v2;
}

// File Line: 166
// RVA: 0x76C310
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::AS3::Value const &>(Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::StringManager *__formal)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  int v3; // eax
  long double v4; // rax

  v2 = result;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v2->Flags = v.Flags;
  v2->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v2->value = v.value;
  v3 = v.Flags & 0x1F;
  if ( v3 > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( v3 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
        return v2;
      }
      if ( v3 > 10 )
      {
        if ( v3 <= 15 )
        {
          v4 = v.value.VNumber;
        }
        else
        {
          if ( v3 > 17 )
            return v2;
          v4 = *(double *)&v.value.VS._2.VObj;
        }
        if ( v4 != 0.0 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v4 + 32i64);
          *(_DWORD *)(*(_QWORD *)&v4 + 32i64) &= 0x8FBFFFFF;
        }
      }
    }
  }
  return v2;
}

// File Line: 195
// RVA: 0x883B60
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,1,0,Scaleform::GFx::ASString const &>(Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::ASString *v2; // rbx

  v2 = result;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(result, sm);
  return v2;
}

// File Line: 1402
// RVA: 0x8D40D0
void __fastcall Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,18,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Func(Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,18,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *> *this, Scaleform::GFx::AS3::ThunkInfo *__formal, Scaleform::GFx::AS3::VM *a3, Scaleform::GFx::AS3::Value *obj, Scaleform::GFx::AS3::Value *result, __int64 argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,18,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)a3->StringManagerRef + (signed int)qword_142440B58),
    obj,
    (unsigned int)result,
    (Scaleform::GFx::AS3::Value *)argc);
}

// File Line: 2156
// RVA: 0x788080
void __fastcall Scaleform::GFx::AS3::UnboxArgV0<bool>::~UnboxArgV0<bool>(Scaleform::GFx::AS3::UnboxArgV0<bool> *this)
{
  Scaleform::GFx::AS3::Value *v1; // rdx
  long double v2; // [rsp+0h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v3; // [rsp+8h] [rbp-10h]

  if ( !this->Vm->HandleException )
  {
    v1 = this->Result;
    LOBYTE(v2) = this->r;
    v1->Flags = v1->Flags & 0xFFFFFFE1 | 1;
    v1->value.VNumber = v2;
    v1->value.VS._2 = v3;
  }
}

// File Line: 2342
// RVA: 0x778A80
void __fastcall Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double>::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double>(Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double> *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv, Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double> *da)
{
  unsigned int v6; // ebp
  Scaleform::GFx::AS3::VM *v7; // rsi
  Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double> *v8; // rbx
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double> *v9; // r14
  Scaleform::GFx::AS3::Value *v10; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rax
  bool v12; // zf
  Scaleform::GFx::AS3::Value v13; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+98h] [rbp+20h]

  v6 = argc;
  v7 = vm;
  v8 = this;
  this->Vm = vm;
  this->Result = result;
  this->r = 0;
  v9 = da;
  this->a0 = da->_0;
  v10 = argv;
  if ( argc )
  {
    v13.Flags = 0;
    v13.Bonus.pWeakProxy = 0i64;
    v11 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &Scaleform::GFx::AS3::fl_geom::Vector3DTI);
    if ( !v11
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v11->vfptr[3].Finalize_GC)(
            v11,
            v10,
            &v13) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v13, v10);
    }
    v8->a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)v13.value.VS._1.VStr;
    if ( (v13.Flags & 0x1F) > 9 )
    {
      if ( (v13.Flags >> 9) & 1 )
      {
        v12 = v13.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v13.Bonus.pWeakProxy = 0i64;
        v13.value = 0ui64;
        v13.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
      }
    }
  }
  v8->a1 = v9->_1;
  if ( !v7->HandleException && v6 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(v10 + 1, &resulta, &v8->a1);
}

// File Line: 2419
// RVA: 0x776760
void __fastcall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &>::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &>(Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &> *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv, Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &> *da)
{
  unsigned int v6; // ebp
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &> *v7; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // rax
  bool v9; // zf
  Scaleform::GFx::AS3::Value *v10; // rax
  Scaleform::GFx::AS3::Value v11; // [rsp+28h] [rbp-30h]

  v6 = argc;
  v7 = this;
  this->Vm = vm;
  this->r = result;
  this->a0 = da->_0;
  if ( argc )
  {
    v11.Flags = 0;
    v11.Bonus.pWeakProxy = 0i64;
    v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &Scaleform::GFx::AS3::fl_text::TextFieldTI);
    if ( !v8
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v8->vfptr[3].Finalize_GC)(
            v8,
            argv,
            &v11) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v11, argv);
    }
    v7->a0 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v11.value.VS._1.VStr;
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags >> 9) & 1 )
      {
        v9 = v11.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v9 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v11.Bonus.pWeakProxy = 0i64;
        v11.value = 0ui64;
        v11.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
      }
    }
  }
  v10 = argv + 1;
  if ( v6 <= 1 )
    v10 = &da->_1;
  v7->a1 = v10;
}

// File Line: 2442
// RVA: 0x779750
void __fastcall Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *>::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *>(Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *> *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv, Scaleform::GFx::AS3::DefArgs3<double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *> *da)
{
  unsigned int v6; // esi
  Scaleform::GFx::AS3::VM *v7; // rbp
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *> *v8; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rax
  bool v10; // zf
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-30h]

  v6 = argc;
  v7 = vm;
  v8 = this;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value,double,long>::UnboxArgV2<Scaleform::GFx::AS3::Value,double,long>(
    (Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value,double,long> *)&this->Vm,
    vm,
    result,
    argc,
    argv,
    (Scaleform::GFx::AS3::DefArgs2<double,long> *)&da->_0);
  v8->a2 = da->_2;
  if ( !v7->HandleException && v6 > 2 )
  {
    v11.Flags = 0;
    v11.Bonus.pWeakProxy = 0i64;
    v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v7, &Scaleform::GFx::AS3::fl_media::SoundTransformTI);
    if ( !v9
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v9->vfptr[3].Finalize_GC)(
            v9,
            argv + 2,
            &v11) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v11, argv + 2);
    }
    v8->a2 = (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)v11.value.VS._1.VStr;
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags >> 9) & 1 )
      {
        v10 = v11.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v11.Bonus.pWeakProxy = 0i64;
        v11.value = 0ui64;
        v11.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
      }
    }
  }
}

// File Line: 2517
// RVA: 0x7799B0
void __fastcall Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *>::UnboxArgV4<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *>(Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *> *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv, Scaleform::GFx::AS3::DefArgs4<Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *> *da)
{
  unsigned int v6; // esi
  Scaleform::GFx::AS3::VM *v7; // rbp
  Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *> *v8; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rax
  bool v10; // zf
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-30h]

  v6 = argc;
  v7 = vm;
  v8 = this;
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::UnboxArgV3<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *>(
    (Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *> *)&this->Vm,
    vm,
    result,
    argc,
    argv,
    (Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *> *)&da->_0);
  v8->a3 = da->_3;
  if ( !v7->HandleException && v6 > 3 )
  {
    v11.Flags = 0;
    v11.Bonus.pWeakProxy = 0i64;
    v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v7, &Scaleform::GFx::AS3::fl_filters::BitmapFilterTI);
    if ( !v9
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v9->vfptr[3].Finalize_GC)(
            v9,
            argv + 3,
            &v11) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v11, argv + 3);
    }
    v8->a3 = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)v11.value.VS._1.VStr;
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags >> 9) & 1 )
      {
        v10 = v11.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v11.Bonus.pWeakProxy = 0i64;
        v11.value = 0ui64;
        v11.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
      }
    }
  }
}

// File Line: 2548
// RVA: 0x779F60
void __fastcall Scaleform::GFx::AS3::UnboxArgV5<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::UnboxArgV5<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>(Scaleform::GFx::AS3::UnboxArgV5<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *> *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv, Scaleform::GFx::AS3::DefArgs5<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *> *da)
{
  unsigned int v6; // esi
  Scaleform::GFx::AS3::VM *v7; // rbp
  Scaleform::GFx::AS3::UnboxArgV5<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *> *v8; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rax
  bool v10; // zf
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-40h]

  v6 = argc;
  v7 = vm;
  v8 = this;
  Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &>::UnboxArgV4<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &>(
    (Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &> *)&this->Vm,
    vm,
    result,
    argc,
    argv,
    (Scaleform::GFx::AS3::DefArgs4<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &> *)&da->_0);
  v8->a4 = da->_4;
  if ( !v7->HandleException && v6 > 4 )
  {
    v11.Flags = 0;
    v11.Bonus.pWeakProxy = 0i64;
    v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v7, &Scaleform::GFx::AS3::fl_geom::RectangleTI);
    if ( !v9
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v9->vfptr[3].Finalize_GC)(
            v9,
            argv + 4,
            &v11) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v11, argv + 4);
    }
    v8->a4 = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)v11.value.VS._1.VStr;
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags >> 9) & 1 )
      {
        v10 = v11.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v11.Bonus.pWeakProxy = 0i64;
        v11.value = 0ui64;
        v11.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
      }
    }
  }
}

// File Line: 2626
// RVA: 0x7431F0
void __fastcall Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,4,Scaleform::GFx::AS3::Value>::Func(Scaleform::GFx::AS3::ThunkInfo *__formal, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *obj, Scaleform::GFx::AS3::Value *result, unsigned int a5, Scaleform::GFx::AS3::Value *a6)
{
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,4,Scaleform::GFx::AS3::Value>::Method(
    (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(*(_QWORD *)&obj->value.VNumber
                                                                    + (signed int)qword_14243C050),
    result);
}

// File Line: 2636
// RVA: 0x876560
void __fastcall Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,26,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,26,Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> *this, Scaleform::GFx::AS3::ThunkInfo *__formal, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *obj, Scaleform::GFx::AS3::Value *result, unsigned int argc)
{
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::ThunkInfo *v7; // rsi
  Scaleform::GFx::AS3::StringManager *v8; // rbp
  Scaleform::GFx::ASStringNode *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  int v12; // ecx
  Scaleform::GFx::ASStringNode *v13; // rdi
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::Value *v16; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::ASString v17; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::ASString v18; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASStringNode *v19; // [rsp+70h] [rbp+18h]

  v6 = obj;
  v7 = __formal;
  v8 = vm->StringManagerRef;
  v9 = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,1,0,Scaleform::GFx::ASString const &>(
         &v18,
         (Scaleform::GFx::AS3::StringManager *)__formal->Name)->pNode;
  v19 = v9;
  ++v9->RefCount;
  v10 = v18.pNode;
  v11 = v18.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v16 = v6;
  v17.pNode = v9;
  ++v9->RefCount;
  if ( (_DWORD)result )
  {
    v12 = **(_DWORD **)&argc & 0x1F;
    if ( (unsigned int)(v12 - 12) > 3 && v12 != 10 || *(_QWORD *)(*(_QWORD *)&argc + 16i64) )
    {
      Scaleform::GFx::AS3::Value::Convert2String(
        *(Scaleform::GFx::AS3::Value **)&argc,
        (Scaleform::GFx::AS3::CheckResult *)&result,
        &v17);
    }
    else
    {
      v13 = &v17.pNode->pManager->NullStringNode;
      ++v17.pNode->pManager->NullStringNode.RefCount;
      v14 = v17.pNode;
      v11 = v17.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v17.pNode = v13;
    }
  }
  if ( !LOBYTE(v7[3].NamespaceName) )
    Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,26,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)v8 + (signed int)qword_14243FBB8),
      v16,
      &v17);
  v15 = v17.pNode;
  v11 = v17.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v11 = v9->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 2653
// RVA: 0x8D1F70
void __fastcall Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Func(Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> *this, Scaleform::GFx::AS3::ThunkInfo *__formal, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *obj)
{
  Scaleform::GFx::AS3::Value *v4; // r15
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::AS3::StringManager *v6; // r14
  Scaleform::GFx::AS3::StringManager *v7; // rbx
  Scaleform::GFx::AS3::Value *v8; // rdi
  Scaleform::GFx::AS3::Value *v9; // rax
  Scaleform::GFx::AS3::VM *v10; // rax
  Scaleform::GFx::AS3::Value *v11; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v12; // [rsp+18h] [rbp-79h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>,Scaleform::GFx::AS3::Value const &> v13; // [rsp+20h] [rbp-71h]
  Scaleform::GFx::AS3::Value::Extra v14; // [rsp+40h] [rbp-51h]
  Scaleform::GFx::AS3::Value::VU v15; // [rsp+48h] [rbp-49h]
  Scaleform::GFx::AS3::Value v16; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::AS3::Value v17; // [rsp+78h] [rbp-19h]
  Scaleform::GFx::AS3::Value v18; // [rsp+98h] [rbp+7h]
  __int64 v19; // [rsp+B8h] [rbp+27h]
  unsigned int v20; // [rsp+108h] [rbp+77h]
  __int64 v21; // [rsp+110h] [rbp+7Fh]

  v19 = -2i64;
  v4 = obj;
  v5 = (Scaleform::GFx::AS3::VM *)__formal;
  v6 = vm->StringManagerRef;
  v7 = (Scaleform::GFx::AS3::StringManager *)__formal->Name;
  v8 = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,9,1,Scaleform::GFx::AS3::Value const &>(
         (Scaleform::GFx::AS3::Value *)((char *)&v17 + 24),
         (Scaleform::GFx::AS3::StringManager *)__formal->Name);
  v9 = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,7,0,Scaleform::GFx::AS3::Value const &>(
         &v18,
         v7);
  LODWORD(v13.a0) = v9->Flags;
  v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v9->Bonus;
  v15 = v9->value;
  if ( (v9->Flags & 0x1F) > 9 )
  {
    if ( (v9->Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v9);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v9);
  }
  v16.Flags = v8->Flags;
  v16.Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
  v16.value = v8->value;
  if ( (v8->Flags & 0x1F) > 9 )
  {
    if ( (v8->Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v8);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v8);
  }
  if ( (v18.Flags & 0x1F) > 9 )
  {
    if ( (v18.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
  }
  if ( (v17.Flags & 0x1F) > 9 )
  {
    if ( (v17.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v17);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v17);
  }
  v13.Vm = v5;
  v13.Result = v4;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>>(
    &v12,
    v5->StringManagerRef);
  v10 = (Scaleform::GFx::AS3::VM *)&v13.a0;
  if ( v20 )
    v10 = (Scaleform::GFx::AS3::VM *)v21;
  v13.Vm = v10;
  v11 = (Scaleform::GFx::AS3::Value *)(v21 + 32);
  if ( v20 <= 1 )
    v11 = &v16;
  v13.Result = v11;
  if ( !v5->HandleException )
    Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v6 + (signed int)qword_142440C88),
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&v12,
      (Scaleform::GFx::AS3::Value *)v13.Vm,
      v13.Result);
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,bool>::~UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,bool>(&v13);
  if ( (v16.Flags & 0x1F) > 9 )
  {
    if ( (v16.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v16);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
  }
  if ( ((_QWORD)v13.a0 & 0x1F) > 9 )
  {
    if ( (LODWORD(v13.a0) >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&v13.a0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v13.a0);
  }
}

// File Line: 2671
// RVA: 0x727500
void __fastcall Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,13,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,double>::Func(Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,13,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,double> *this, Scaleform::GFx::AS3::ThunkInfo *__formal, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *obj, Scaleform::GFx::AS3::Value *result, unsigned int argc)
{
  Scaleform::GFx::AS3::Value *v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // rdi
  Scaleform::GFx::AS3::StringManager *v8; // r14
  double v9; // xmm6_8
  Scaleform::GFx::AS3::Value *v10; // rbp
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *> da; // [rsp+38h] [rbp-60h]
  double v12; // [rsp+48h] [rbp-50h]
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *> v13; // [rsp+50h] [rbp-48h]
  long double v14; // [rsp+78h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult v15; // [rsp+A8h] [rbp+10h]

  v6 = obj;
  v7 = (Scaleform::GFx::AS3::VM *)__formal;
  v8 = vm->StringManagerRef;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  da._0 = 0i64;
  da._1 = 0i64;
  v12 = v9;
  v10 = *(Scaleform::GFx::AS3::Value **)&argc;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>(
    &v13,
    v7,
    v6,
    (unsigned int)result,
    *(Scaleform::GFx::AS3::Value **)&argc,
    &da);
  v14 = v9;
  if ( !v7->HandleException && (unsigned int)result > 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(v10 + 2, &v15, &v14);
  if ( !v7->HandleException )
    Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,13,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,double>::Method(
      (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)((char *)v8 + (signed int)qword_14243E320),
      &v13.r,
      v13.a0,
      v13.a1,
      v14);
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,double>::~UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,double>((Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>,Scaleform::GFx::AS3::Value const &> *)&v13);
}

// File Line: 2690
// RVA: 0x74A0E0
void __fastcall Scaleform::GFx::AS3::ThunkFunc4<Scaleform::GFx::AS3::Instances::fl_display::Graphics,4,Scaleform::GFx::AS3::Value const,double,double,double,double>::Func(Scaleform::GFx::AS3::ThunkInfo *__formal, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *obj, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  long double v6; // rbp
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rdi
  long double v9; // xmm6_8
  double v10; // xmm8_8
  double v11; // xmm7_8
  long double v12; // xmm0_8
  unsigned int v13; // esi
  Scaleform::GFx::AS3::Value *v14; // rbx
  bool v15; // zf
  Scaleform::GFx::AS3::Value *v16; // [rsp+38h] [rbp-60h]
  long double resulta; // [rsp+40h] [rbp-58h]
  long double v18; // [rsp+48h] [rbp-50h]
  long double v19; // [rsp+50h] [rbp-48h]
  long double v20; // [rsp+58h] [rbp-40h]

  v6 = obj->value.VNumber;
  v7 = result;
  v8 = vm;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  v10 = Scaleform::GFx::NumberUtil::NaN();
  v11 = Scaleform::GFx::NumberUtil::NaN();
  v12 = Scaleform::GFx::NumberUtil::NaN();
  v13 = argc;
  v16 = v7;
  v14 = argv;
  resulta = v12;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta);
  v15 = v8->HandleException == 0;
  v18 = v11;
  if ( v15 && v13 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &v18);
  v15 = v8->HandleException == 0;
  v19 = v10;
  if ( v15 && v13 > 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, &v19);
  v15 = v8->HandleException == 0;
  v20 = v9;
  if ( v15 )
  {
    if ( v13 > 3 )
    {
      Scaleform::GFx::AS3::Value::Convert2Number(v14 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, &v20);
      v9 = v20;
    }
    if ( !v8->HandleException )
      Scaleform::GFx::AS3::ThunkFunc4<Scaleform::GFx::AS3::Instances::fl_display::Graphics,4,Scaleform::GFx::AS3::Value const,double,double,double,double>::Method(
        (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)(*(_QWORD *)&v6 + (signed int)qword_14243BEC0),
        v16,
        resulta,
        v18,
        v19,
        v9);
  }
}

// File Line: 2710
// RVA: 0x731490
void __fastcall Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::Stage,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool>::Func(Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::Stage,40,Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool> *this, Scaleform::GFx::AS3::ThunkInfo *__formal, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *obj)
{
  Scaleform::GFx::AS3::Value *v4; // r14
  Scaleform::GFx::AS3::ThunkInfo *v5; // rsi
  Scaleform::GFx::AS3::StringManager *v6; // r15
  Scaleform::GFx::AS3::StringManager *v7; // rbx
  Scaleform::GFx::AS3::Value *v8; // rdi
  int v9; // eax
  long double v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  int v13; // ecx
  Scaleform::GFx::ASStringNode *v14; // r14
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::Value *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString v19; // [rsp+28h] [rbp-79h]
  Scaleform::GFx::AS3::Value *v20; // [rsp+30h] [rbp-71h]
  char v21; // [rsp+38h] [rbp-69h]
  int v22[2]; // [rsp+40h] [rbp-61h]
  Scaleform::GFx::AS3::Value *v23; // [rsp+48h] [rbp-59h]
  Scaleform::GFx::ASStringNode *v24; // [rsp+58h] [rbp-49h]
  Scaleform::GFx::AS3::Value v25; // [rsp+60h] [rbp-41h]
  char v26; // [rsp+80h] [rbp-21h]
  int v27; // [rsp+88h] [rbp-19h]
  char v28; // [rsp+90h] [rbp-11h]
  Scaleform::GFx::AS3::Value v29; // [rsp+98h] [rbp-9h]
  __int64 v30; // [rsp+B8h] [rbp+17h]
  __int64 v31; // [rsp+C0h] [rbp+1Fh]
  Scaleform::GFx::ASString v32; // [rsp+100h] [rbp+5Fh]
  void *retaddr; // [rsp+118h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v34; // [rsp+120h] [rbp+7Fh]

  v30 = -2i64;
  v4 = obj;
  v5 = __formal;
  v6 = vm->StringManagerRef;
  v7 = (Scaleform::GFx::AS3::StringManager *)__formal->Name;
  v8 = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,7,0,Scaleform::GFx::AS3::Value const &>(
         (Scaleform::GFx::AS3::Value *)&v31,
         (Scaleform::GFx::AS3::StringManager *)__formal->Name);
  v24 = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,1,0,Scaleform::GFx::ASString const &>(
          &v32,
          v7)->pNode;
  ++v24->RefCount;
  v25.Flags = v8->Flags;
  v25.Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
  v25.value = v8->value;
  v9 = v8->Flags & 0x1F;
  if ( v9 > 9 )
  {
    if ( (v8->Flags >> 9) & 1 )
    {
      ++v8->Bonus.pWeakProxy->RefCount;
      goto LABEL_13;
    }
    if ( v9 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v8->value.VNumber + 24i64);
    }
    else
    {
      if ( v9 <= 10 )
        goto LABEL_13;
      if ( v9 <= 15 )
      {
        v10 = v8->value.VNumber;
      }
      else
      {
        if ( v9 > 17 )
          goto LABEL_13;
        v10 = *(double *)&v8->value.VS._2.VObj;
      }
      if ( v10 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v10 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v10 + 32i64) + 1) & 0x8FBFFFFF;
    }
  }
LABEL_13:
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v11 = v32.pNode;
  v12 = v32.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( (v29.Flags & 0x1F) > 9 )
  {
    if ( (v29.Flags >> 9) & 1 )
    {
      v12 = v29.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v29.Bonus.pWeakProxy = 0i64;
      v29.value = 0ui64;
      v29.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
    }
  }
  *(_QWORD *)v22 = v5;
  v23 = v4;
  v19.pNode = v24;
  ++v19.pNode->RefCount;
  if ( (_DWORD)retaddr )
  {
    v13 = v34->Flags & 0x1F;
    if ( (unsigned int)(v13 - 12) > 3 && v13 != 10 || *(_QWORD *)&v34->value.VNumber )
    {
      Scaleform::GFx::AS3::Value::Convert2String(v34, (Scaleform::GFx::AS3::CheckResult *)&retaddr, &v19);
    }
    else
    {
      v14 = &v19.pNode->pManager->NullStringNode;
      ++v19.pNode->pManager->NullStringNode.RefCount;
      v15 = v19.pNode;
      v12 = v19.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      v19.pNode = v14;
    }
  }
  v16 = v34 + 1;
  if ( (unsigned int)retaddr <= 1 )
    v16 = &v25;
  v20 = v16;
  v21 = v26;
  if ( !LOBYTE(v5[3].NamespaceName) && (unsigned int)retaddr > 2 )
    v21 = Scaleform::GFx::AS3::Value::Convert2Boolean(v34 + 2);
  v22[0] = v27;
  if ( !LOBYTE(v5[3].NamespaceName) && (unsigned int)retaddr > 3 )
    Scaleform::GFx::AS3::Value::Convert2Int32(v34 + 3, (Scaleform::GFx::AS3::CheckResult *)&retaddr, v22);
  LOBYTE(v23) = v28;
  if ( !LOBYTE(v5[3].NamespaceName) && (unsigned int)retaddr > 4 )
    LOBYTE(v23) = Scaleform::GFx::AS3::Value::Convert2Boolean(v34 + 4);
  if ( !LOBYTE(v5[3].NamespaceName) )
  {
    LOBYTE(v20) = (_BYTE)v23;
    Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::Stage,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool>::Method(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)((char *)v6 + (signed int)qword_14243C8B0),
      v23,
      &v19,
      v20,
      v21,
      v22[0],
      (bool)v23);
  }
  v17 = v19.pNode;
  v12 = v19.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( (v25.Flags & 0x1F) > 9 )
  {
    if ( (v25.Flags >> 9) & 1 )
    {
      v12 = v25.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&v25.Bonus, (__m128i)0i64);
      v25.value.VS._2.VObj = 0i64;
      v25.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v25);
    }
  }
  v18 = v24;
  v12 = v24->RefCount == 1;
  --v18->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
}

// File Line: 2731
// RVA: 0x757250
void __fastcall Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::Graphics,10,Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>::Func(Scaleform::GFx::AS3::ThunkInfo *__formal, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *obj, Scaleform::GFx::AS3::Value *result, unsigned int argc)
{
  long double v5; // r14
  Scaleform::GFx::AS3::Value *v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // rdi
  long double v8; // xmm6_8
  long double v9; // xmm10_8
  long double v10; // xmm9_8
  double v11; // xmm8_8
  double v12; // xmm7_8
  long double v13; // xmm0_8
  Scaleform::GFx::AS3::Value *v14; // rsi
  unsigned int v15; // ebx
  bool v16; // zf
  Scaleform::GFx::AS3::Value *v17; // [rsp+40h] [rbp-41h]
  long double v18; // [rsp+48h] [rbp-39h]
  long double v19; // [rsp+50h] [rbp-31h]
  long double v20; // [rsp+58h] [rbp-29h]
  __int128 v21; // [rsp+60h] [rbp-21h]
  long double v22; // [rsp+70h] [rbp-11h]
  unsigned int resulta; // [rsp+F8h] [rbp+77h]

  v5 = obj->value.VNumber;
  v6 = result;
  v7 = vm;
  v8 = Scaleform::GFx::NumberUtil::NaN();
  v9 = Scaleform::GFx::NumberUtil::NaN();
  v10 = Scaleform::GFx::NumberUtil::NaN();
  v11 = Scaleform::GFx::NumberUtil::NaN();
  v12 = Scaleform::GFx::NumberUtil::NaN();
  v13 = Scaleform::GFx::NumberUtil::NaN();
  v14 = *(Scaleform::GFx::AS3::Value **)&argc;
  v17 = v6;
  v15 = resulta;
  v18 = v13;
  if ( resulta )
    Scaleform::GFx::AS3::Value::Convert2Number(
      *(Scaleform::GFx::AS3::Value **)&argc,
      (Scaleform::GFx::AS3::CheckResult *)&resulta,
      &v18);
  v16 = v7->HandleException == 0;
  v19 = v12;
  if ( v16 && v15 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 1, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v19);
  v16 = v7->HandleException == 0;
  v20 = v11;
  if ( v16 && v15 > 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 2, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v20);
  v16 = v7->HandleException == 0;
  *(long double *)&v21 = v10;
  if ( v16 && v15 > 3 )
    Scaleform::GFx::AS3::Value::Convert2Number(
      v14 + 3,
      (Scaleform::GFx::AS3::CheckResult *)&resulta,
      (long double *)&v21);
  v16 = v7->HandleException == 0;
  *((long double *)&v21 + 1) = v9;
  if ( v16 && v15 > 4 )
    Scaleform::GFx::AS3::Value::Convert2Number(
      v14 + 4,
      (Scaleform::GFx::AS3::CheckResult *)&resulta,
      (long double *)&v21 + 1);
  v16 = v7->HandleException == 0;
  v22 = v8;
  if ( v16 )
  {
    if ( v15 > 5 )
    {
      Scaleform::GFx::AS3::Value::Convert2Number(v14 + 5, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v22);
      v8 = v22;
    }
    if ( !v7->HandleException )
      Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::Graphics,10,Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>::Method(
        (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)(*(_QWORD *)&v5 + (signed int)qword_14243BF20),
        v17,
        v18,
        v19,
        v20,
        *(long double *)&v21,
        *((long double *)&v21 + 1),
        v8);
  }
}

