// File Line: 42
// RVA: 0x920FA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::inputModeGet(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::AS3::VM *v3; // r9
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v4; // rcx
  Scaleform::GFx::ASStringNode *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rdi
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rdi
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString v15; // [rsp+20h] [rbp-18h]
  __int64 v16; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString v18; // [rsp+50h] [rbp+18h]
  Scaleform::GFx::ASString v19; // [rsp+58h] [rbp+20h]

  v16 = -2i64;
  v2 = result;
  v3 = this->pTraits.pObject->pVM;
  v4 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->StringManagerRef->Builtins;
  switch ( *((_DWORD *)v3[1].vfptr[2].__vecDelDtor + 5400) )
  {
    case 1:
      v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              v4,
              &v15,
              "touchPoint")->pNode;
      ++v13->RefCount;
      v14 = v2->pNode;
      v7 = v2->pNode->RefCount == 1;
      --v14->RefCount;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v2->pNode = v13;
      v8 = v15.pNode;
      break;
    case 2:
      v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              v4,
              &v19,
              "gesture")->pNode;
      ++v11->RefCount;
      v12 = v2->pNode;
      v7 = v2->pNode->RefCount == 1;
      --v12->RefCount;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v2->pNode = v11;
      v8 = v19.pNode;
      break;
    case 3:
      v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             v4,
             &v18,
             "mixed")->pNode;
      ++v9->RefCount;
      v10 = v2->pNode;
      v7 = v2->pNode->RefCount == 1;
      --v10->RefCount;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      v2->pNode = v9;
      v8 = v18.pNode;
      break;
    default:
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             v4,
             &resulta,
             "none")->pNode;
      ++v5->RefCount;
      v6 = v2->pNode;
      v7 = v2->pNode->RefCount == 1;
      --v6->RefCount;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      v2->pNode = v5;
      v8 = resulta.pNode;
      break;
  }
  v7 = v8->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 64
// RVA: 0x9210C0
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::inputModeSet(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::VM *v3; // rsi
  unsigned int v4; // edi
  const char *v5; // rbx
  __int64 v6; // rcx
  char v7; // al
  __int64 v8; // rax
  char v9; // cl
  bool v10; // zf
  void *(__fastcall *v11)(Scaleform::GFx::AS3::VM *, unsigned int); // rbx
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h]

  v3 = this->pTraits.pObject->pVM;
  v4 = 0;
  v5 = value->pNode->pData;
  if ( !strcmp(value->pNode->pData, "touchPoint") )
  {
    v4 = 1;
  }
  else
  {
    v6 = 0i64;
    while ( 1 )
    {
      v7 = v5[v6++];
      if ( v7 != aGesture_0[v6 - 1] )
        break;
      if ( v6 == 8 )
      {
        v4 = 2;
        goto LABEL_13;
      }
    }
    v8 = 0i64;
    while ( 1 )
    {
      v9 = v5[v8++];
      v10 = v9 == aMixed[v8 - 1];
      if ( v9 != aMixed[v8 - 1] )
        break;
      if ( v8 == 6 )
      {
        v10 = v9 == aMixed[5];
        break;
      }
    }
    if ( v10 )
      v4 = 3;
  }
LABEL_13:
  v11 = v3[1].vfptr[2].__vecDelDtor;
  Scaleform::GFx::StateBag::GetMultitouchInterface((Scaleform::GFx::StateBag *)v11 + 2, &resulta);
  if ( resulta.pObject
    && (unsigned __int8)resulta.pObject->vfptr[3].__vecDelDtor((Scaleform::RefCountImplCore *)resulta.pObject, v4) )
  {
    *((_DWORD *)v11 + 5400) = v4;
  }
  if ( resulta.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
}

// File Line: 79
// RVA: 0x921650
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::maxTouchPointsGet(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this, int *result)
{
  int *v2; // rbx
  int v3; // edi
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  Scaleform::GFx::StateBag::GetMultitouchInterface(
    (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__cdecl *)(Scaleform::GFx::MultitouchInterface *))resulta.pObject->vfptr[1].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    *v2 = v3;
  }
  else
  {
    *v2 = 0;
  }
}

// File Line: 87
// RVA: 0x926C80
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportedGesturesGet(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *v2; // rsi
  Scaleform::GFx::AS3::VM *v3; // rbp
  char v4; // di
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *v5; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *v6; // rax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  v3 = this->pTraits.pObject->pVM;
  Scaleform::GFx::StateBag::GetMultitouchInterface(
    (Scaleform::GFx::StateBag *)v3[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v4 = ((__int64 (__cdecl *)(Scaleform::GFx::MultitouchInterface *))resulta.pObject->vfptr[2].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
  else
  {
    v4 = 0;
  }
  v5 = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *)Scaleform::GFx::AS3::VM::GetITraitsVectorString(v3);
  v6 = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *)&resulta,
         v5);
  v7 = v6->pV;
  v8 = v2->pObject;
  if ( v6->pV != v2->pObject )
  {
    if ( v8 )
    {
      if ( (unsigned __int8)v8 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)((char *)v8 - 1);
      }
      else
      {
        v9 = v8->RefCount;
        if ( v9 & 0x3FFFFF )
        {
          v8->RefCount = v9 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
        }
      }
    }
    v2->pObject = v7;
  }
  if ( v4 & 1 )
  {
    v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->StringManagerRef->Builtins,
            (Scaleform::GFx::ASString *)&resulta,
            "pan");
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(v2->pObject, v10->pNode);
    v11 = (Scaleform::GFx::ASStringNode *)resulta.pObject;
    v12 = LODWORD(resulta.pObject[1].vfptr) == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( v4 & 4 )
  {
    v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->StringManagerRef->Builtins,
            (Scaleform::GFx::ASString *)&resulta,
            "rotate");
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(v2->pObject, v13->pNode);
    v14 = (Scaleform::GFx::ASStringNode *)resulta.pObject;
    v12 = LODWORD(resulta.pObject[1].vfptr) == 1;
    --v14->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  if ( v4 & 8 )
  {
    v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->StringManagerRef->Builtins,
            (Scaleform::GFx::ASString *)&resulta,
            "swipe");
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(v2->pObject, v15->pNode);
    v16 = (Scaleform::GFx::ASStringNode *)resulta.pObject;
    v12 = LODWORD(resulta.pObject[1].vfptr) == 1;
    --v16->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  if ( v4 & 2 )
  {
    v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->StringManagerRef->Builtins,
            (Scaleform::GFx::ASString *)&resulta,
            "zoom");
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(v2->pObject, v17->pNode);
    v18 = (Scaleform::GFx::ASStringNode *)resulta.pObject;
    v12 = LODWORD(resulta.pObject[1].vfptr) == 1;
    --v18->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
}

// File Line: 107
// RVA: 0x926E40
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportsGestureEventsGet(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this, bool *result)
{
  bool *v2; // rdi
  int v3; // ebx
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  Scaleform::GFx::StateBag::GetMultitouchInterface(
    (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__cdecl *)(Scaleform::GFx::MultitouchInterface *))resulta.pObject->vfptr[2].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
  else
  {
    v3 = 0;
  }
  *v2 = v3 != 0;
}

// File Line: 116
// RVA: 0x926ED0
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportsTouchEventsGet(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this, bool *result)
{
  bool *v2; // rdi
  int v3; // ebx
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  Scaleform::GFx::StateBag::GetMultitouchInterface(
    (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__cdecl *)(Scaleform::GFx::MultitouchInterface *))resulta.pObject->vfptr[1].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
  else
  {
    v3 = 0;
  }
  *v2 = v3 != 0;
}

// File Line: 137
// RVA: 0x15983B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Multitouch_0_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_1424402F8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,0,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::inputModeGet;
  return result;
}

// File Line: 138
// RVA: 0x1599E20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_ui::Multitouch_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440308 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::inputModeSet;
  return result;
}

// File Line: 139
// RVA: 0x15982F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Multitouch_2_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440318 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,2,long>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::maxTouchPointsGet;
  return result;
}

// File Line: 140
// RVA: 0x1598320
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Multitouch_3_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440328 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,3,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportedGesturesGet;
  return result;
}

// File Line: 141
// RVA: 0x1598350
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Multitouch_4_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440338 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,4,bool>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportsGestureEventsGet;
  return result;
}

// File Line: 142
// RVA: 0x1598380
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Multitouch_5_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440348 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,5,bool>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportsTouchEventsGet;
  return result;
}

// File Line: 175
// RVA: 0x87C600
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_ui::Multitouch::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // r14
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_ui::MultitouchCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_ui::Multitouch::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, v2, &Scaleform::GFx::AS3::fl_ui::MultitouchCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                        v4,
                                        72i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, v3->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::`vftable;
  }
  return v3;
}

