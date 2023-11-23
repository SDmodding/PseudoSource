// File Line: 42
// RVA: 0x920FA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::inputModeGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM *pVM; // r9
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // rcx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rdi
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rdi
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString v19; // [rsp+20h] [rbp-18h] BYREF
  __int64 v20; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v22; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::GFx::ASString v23; // [rsp+58h] [rbp+20h] BYREF

  v20 = -2i64;
  pVM = this->pTraits.pObject->pVM;
  StringManagerRef = pVM->StringManagerRef;
  switch ( *((_DWORD *)pVM[1].vfptr[2].__vecDelDtor + 5400) )
  {
    case 1:
      v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              StringManagerRef,
              &v19,
              "touchPoint");
      pNode = v16->pNode;
      ++v16->pNode->RefCount;
      v18 = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      result->pNode = pNode;
      v9 = v19.pNode;
      break;
    case 2:
      v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              StringManagerRef,
              &v23,
              "gesture");
      v14 = v13->pNode;
      ++v13->pNode->RefCount;
      v15 = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      result->pNode = v14;
      v9 = v23.pNode;
      break;
    case 3:
      v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              StringManagerRef,
              &v22,
              "mixed");
      v11 = v10->pNode;
      ++v10->pNode->RefCount;
      v12 = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      result->pNode = v11;
      v9 = v22.pNode;
      break;
    default:
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             StringManagerRef,
             &resulta,
             "none");
      v6 = v5->pNode;
      ++v5->pNode->RefCount;
      v7 = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      result->pNode = v6;
      v9 = resulta.pNode;
      break;
  }
  v8 = v9->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 64
// RVA: 0x9210C0
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::inputModeSet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::VM *pVM; // rsi
  unsigned int v4; // edi
  const char *pData; // rbx
  __int64 v6; // rcx
  char v7; // al
  __int64 v8; // rax
  char v9; // cl
  bool v10; // zf
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rbx
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v4 = 0;
  pData = value->pNode->pData;
  if ( !strcmp(pData, "touchPoint") )
  {
    v4 = 1;
  }
  else
  {
    v6 = 0i64;
    while ( 1 )
    {
      v7 = pData[v6++];
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
      v9 = pData[v8++];
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
  vecDelDtor = pVM[1].vfptr[2].__vecDelDtor;
  Scaleform::GFx::StateBag::GetMultitouchInterface((Scaleform::GFx::StateBag *)vecDelDtor + 2, &resulta);
  if ( resulta.pObject && resulta.pObject->vfptr[3].__vecDelDtor(resulta.pObject, v4) )
    *((_DWORD *)vecDelDtor + 5400) = v4;
  if ( resulta.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
}

// File Line: 79
// RVA: 0x921650
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::maxTouchPointsGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        int *result)
{
  int v3; // edi
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetMultitouchInterface(
    (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::MultitouchInterface *))resulta.pObject->vfptr[1].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    *result = v3;
  }
  else
  {
    *result = 0;
  }
}

// File Line: 87
// RVA: 0x926C80
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportedGesturesGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rbp
  char v4; // di
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *ITraitsVectorString; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *Instance; // rax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *pV; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString *ConstString; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::StateBag::GetMultitouchInterface(
    (Scaleform::GFx::StateBag *)pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v4 = ((__int64 (__fastcall *)(Scaleform::GFx::MultitouchInterface *))resulta.pObject->vfptr[2].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
  else
  {
    v4 = 0;
  }
  ITraitsVectorString = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *)Scaleform::GFx::AS3::VM::GetITraitsVectorString(pVM);
  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *)&resulta,
               ITraitsVectorString);
  pV = Instance->pV;
  pObject = result->pObject;
  if ( Instance->pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  if ( (v4 & 1) != 0 )
  {
    ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                    pVM->StringManagerRef,
                    (Scaleform::GFx::ASString *)&resulta,
                    "pan");
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(result->pObject, ConstString->pNode);
    v11 = (Scaleform::GFx::ASStringNode *)resulta.pObject;
    v12 = LODWORD(resulta.pObject[1].vfptr)-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( (v4 & 4) != 0 )
  {
    v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            pVM->StringManagerRef,
            (Scaleform::GFx::ASString *)&resulta,
            "rotate");
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(result->pObject, v13->pNode);
    v14 = (Scaleform::GFx::ASStringNode *)resulta.pObject;
    v12 = LODWORD(resulta.pObject[1].vfptr)-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  if ( (v4 & 8) != 0 )
  {
    v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            pVM->StringManagerRef,
            (Scaleform::GFx::ASString *)&resulta,
            "swipe");
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(result->pObject, v15->pNode);
    v16 = (Scaleform::GFx::ASStringNode *)resulta.pObject;
    v12 = LODWORD(resulta.pObject[1].vfptr)-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  if ( (v4 & 2) != 0 )
  {
    v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            pVM->StringManagerRef,
            (Scaleform::GFx::ASString *)&resulta,
            "zoom");
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(result->pObject, v17->pNode);
    v18 = (Scaleform::GFx::ASStringNode *)resulta.pObject;
    v12 = LODWORD(resulta.pObject[1].vfptr)-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
}

// File Line: 107
// RVA: 0x926E40
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportsGestureEventsGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        bool *result)
{
  int v3; // ebx
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetMultitouchInterface(
    (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::MultitouchInterface *))resulta.pObject->vfptr[2].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
  else
  {
    v3 = 0;
  }
  *result = v3 != 0;
}

// File Line: 116
// RVA: 0x926ED0
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportsTouchEventsGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        bool *result)
{
  int v3; // ebx
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetMultitouchInterface(
    (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
    &resulta);
  if ( resulta.pObject )
  {
    v3 = ((__int64 (__fastcall *)(Scaleform::GFx::MultitouchInterface *))resulta.pObject->vfptr[1].__vecDelDtor)(resulta.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
  else
  {
    v3 = 0;
  }
  *result = v3 != 0;
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_ui::Multitouch::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_ui::MultitouchCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_ui::Multitouch::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, vm, &Scaleform::GFx::AS3::fl_ui::MultitouchCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                        MHeap,
                                        72i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, result->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::`vftable;
  }
  return result;
}

