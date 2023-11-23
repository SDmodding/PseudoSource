// File Line: 29
// RVA: 0x77B250
void __fastcall Scaleform::GFx::AS3::AvmTextField::AvmTextField(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::TextField *ptf)
{
  Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(this, ptf);
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmTextFieldBase::`vftable;
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmTextField::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmTextField::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmTextField::`vftable;
  ptf->Flags |= 2u;
  Scaleform::GFx::TextField::SetSelection(ptf, 0i64, 0i64);
}

// File Line: 66
// RVA: 0x804EB0
char __fastcall Scaleform::GFx::AS3::AvmTextField::OnMouseEvent(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::EventId *event)
{
  Scaleform::GFx::TextField *pClassName; // rdi
  unsigned __int64 BeginIndex; // rbx
  unsigned __int64 CharIndexAtPoint; // rax
  unsigned __int64 v7; // r12
  Scaleform::GFx::StateBag *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pDispObj; // rdi
  Scaleform::GFx::AS3::ASVM *v10; // r15
  Scaleform::GFx::AS3::Object **p_pObject; // r8
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v12; // rbx
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::UrlNavigator *pObject; // rbx
  Scaleform::GFx::ASString v20[2]; // [rsp+30h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value ptr; // [rsp+40h] [rbp-49h] BYREF
  int v22; // [rsp+60h] [rbp-29h]
  __int64 v23; // [rsp+68h] [rbp-21h]
  char v24; // [rsp+70h] [rbp-19h]
  int v25; // [rsp+80h] [rbp-9h]
  __int64 v26; // [rsp+88h] [rbp-1h]
  char v27; // [rsp+90h] [rbp+7h]
  __int64 v28; // [rsp+A0h] [rbp+17h]
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+F8h] [rbp+6Fh] BYREF
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+100h] [rbp+77h] BYREF
  Scaleform::Render::Point<float> pPnt; // [rsp+108h] [rbp+7Fh] BYREF

  v28 = -2i64;
  Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent((Scaleform::GFx::AS3::AvmTextField *)((char *)this - 72), event);
  if ( event->Id != 16777228 )
    return 0;
  pClassName = (Scaleform::GFx::TextField *)this[-1].pClassName;
  BeginIndex = Scaleform::GFx::TextField::GetBeginIndex(pClassName);
  if ( BeginIndex != Scaleform::GFx::TextField::GetEndIndex(pClassName) )
    return 0;
  if ( (pClassName->Flags & 2) != 0
    && (pClassName->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0
    && Scaleform::GFx::TextField::IsUrlUnderMouseCursor(pClassName, event->ControllerIndex, &pPnt, 0i64) )
  {
    CharIndexAtPoint = Scaleform::Render::Text::DocView::GetCharIndexAtPoint(
                         pClassName->pDocument.pObject,
                         pPnt.x,
                         pPnt.y);
    if ( CharIndexAtPoint != -1i64
      && Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
           pClassName->pDocument.pObject->pDocument.pObject,
           &ppdestTextFmt,
           0i64,
           CharIndexAtPoint)
      && Scaleform::Render::Text::TextFormat::IsUrlSet(ppdestTextFmt) )
    {
      v7 = ppdestTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      v8 = *(Scaleform::GFx::StateBag **)(*((_QWORD *)this[-1].pClassName + 4) + 16i64);
      if ( !v8 || Scaleform::String::CompareNoCase((const char *)(v7 + 12), "event:", 6i64) )
      {
        pObject = Scaleform::GFx::StateBag::GetUrlNavigator(
                    v8 + 2,
                    (Scaleform::Ptr<Scaleform::GFx::UrlNavigator> *)&result)->pObject;
        if ( result.pNode )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pNode);
        if ( pObject )
          pObject->vfptr[1].__vecDelDtor(pObject, (unsigned int)&ppdestTextFmt->Url);
      }
      else
      {
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)this[-1].pClassName
                                                                                                + 4)
                                                                                              + 360i64),
          &result,
          "link");
        pDispObj = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this[-1].pDispObj;
        if ( !pDispObj )
          pDispObj = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this[-1].pAS3RawPtr;
        if ( ((unsigned __int8)pDispObj & 1) != 0 )
          pDispObj = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pDispObj - 1);
        if ( pDispObj
          && (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
                (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)pDispObj,
                &result,
                0)
           || Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
                (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)pDispObj,
                &result,
                1)) )
        {
          pobj.pObject = 0i64;
          ptr.Flags = 10;
          ptr.Bonus.pWeakProxy = 0i64;
          *(Scaleform::GFx::ASString *)&ptr.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
          if ( result.pNode == &result.pNode->pManager->NullStringNode )
          {
            v20[0].pNode = 0i64;
            ptr.value = *(Scaleform::GFx::AS3::Value::VU *)&v20[0].pNode;
            ptr.Flags = 12;
          }
          else
          {
            ++result.pNode->RefCount;
          }
          v22 = 1;
          v23 = 0i64;
          v24 = 1;
          v25 = 1;
          v26 = 0i64;
          v27 = 1;
          v10 = *(Scaleform::GFx::AS3::ASVM **)(*((_QWORD *)this[-1].pClassName + 4) + 80i64);
          p_pObject = &v10->TextEventExClass.pObject;
          if ( !v10->ExtensionsEnabled )
            p_pObject = &v10->TextEventClass.pObject;
          Scaleform::GFx::AS3::ASVM::_constructInstance(v10, &pobj, *p_pObject, 3u, &ptr);
          v12 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)pobj.pObject;
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pobj.pObject[1].16,
            pDispObj);
          String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                     (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)this[-1].pClassName + 4) + 360i64),
                     v20,
                     (const char *)(v7 + 18));
          Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(v12, String);
          pNode = v20[0].pNode;
          v15 = v20[0].pNode->RefCount-- == 1;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          if ( v10->ExtensionsEnabled )
          {
            LODWORD(v12[1].vfptr) = event->ControllerIndex;
            HIDWORD(v12[1].vfptr) = (unsigned __int8)event->AsciiCode;
          }
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)pDispObj,
            v12,
            (Scaleform::GFx::DisplayObject *)this[-1].pClassName);
          `eh vector destructor iterator(
            &ptr,
            0x20ui64,
            3,
            (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
          if ( v12 )
          {
            if ( ((unsigned __int8)v12 & 1) != 0 )
            {
              pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)((char *)v12 - 1);
            }
            else
            {
              RefCount = v12->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v12->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
              }
            }
          }
        }
        v17 = result.pNode;
        v15 = result.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      }
    }
  }
  return 1;
}

// File Line: 153
// RVA: 0x804BA0
void __fastcall Scaleform::GFx::AS3::AvmTextField::OnLinkEventEx(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::TextField::LinkEvent event,
        unsigned int pos,
        unsigned int controllerIndex)
{
  unsigned __int64 v8; // r14
  int v9; // ebx
  const char *v10; // r8
  Scaleform::GFx::AS3::Instances::fl::XMLList *pDispObj; // rbx
  Scaleform::GFx::AS3::ASVM *v12; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *pObject; // rdi
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v16; // zf
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+18h] [rbp-49h] BYREF
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+20h] [rbp-41h] BYREF
  Scaleform::GFx::ASString v21[2]; // [rsp+28h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+38h] [rbp-29h] BYREF
  int v23; // [rsp+58h] [rbp-9h]
  __int64 v24; // [rsp+60h] [rbp-1h]
  char v25; // [rsp+68h] [rbp+7h]
  int v26; // [rsp+78h] [rbp+17h]
  __int64 v27; // [rsp+80h] [rbp+1Fh]
  char v28; // [rsp+88h] [rbp+27h]
  __int64 v29; // [rsp+98h] [rbp+37h]
  Scaleform::GFx::ASString result; // [rsp+C8h] [rbp+67h] BYREF

  v29 = -2i64;
  (*(void (__fastcall **)(_QWORD))(**((_QWORD **)this[-1].pClassName + 4) + 32i64))(*((_QWORD *)this[-1].pClassName + 4));
  if ( *(_BYTE *)(*(_QWORD *)(*((_QWORD *)this[-1].pClassName + 4) + 80i64) + 976i64)
    && Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
         *(Scaleform::Render::Text::StyledText **)(*((_QWORD *)this[-1].pClassName + 28) + 16i64),
         &ppdestTextFmt,
         0i64,
         pos)
    && (ppdestTextFmt->PresentMask & 0x100) != 0
    && Scaleform::String::GetLength(&ppdestTextFmt->Url) )
  {
    v8 = ppdestTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    v9 = event - 2;
    if ( v9 )
    {
      if ( v9 != 1 )
        return;
      v10 = "linkMouseOut";
    }
    else
    {
      v10 = "linkMouseOver";
    }
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)this[-1].pClassName
                                                                                            + 4)
                                                                                          + 360i64),
      &result,
      v10);
    pDispObj = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this[-1].pDispObj;
    if ( !pDispObj )
      pDispObj = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this[-1].pAS3RawPtr;
    if ( ((unsigned __int8)pDispObj & 1) != 0 )
      pDispObj = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pDispObj - 1);
    if ( pDispObj
      && (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)pDispObj,
            &result,
            0)
       || Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)pDispObj,
            &result,
            1)) )
    {
      pobj.pObject = 0i64;
      argv.Flags = 10;
      argv.Bonus.pWeakProxy = 0i64;
      *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
      if ( result.pNode == &result.pNode->pManager->NullStringNode )
      {
        v21[0].pNode = 0i64;
        argv.value = *(Scaleform::GFx::AS3::Value::VU *)&v21[0].pNode;
        argv.Flags = 12;
      }
      else
      {
        ++result.pNode->RefCount;
      }
      v23 = 1;
      v24 = 0i64;
      v25 = 1;
      v26 = 1;
      v27 = 0i64;
      v28 = 1;
      v12 = *(Scaleform::GFx::AS3::ASVM **)(*((_QWORD *)this[-1].pClassName + 4) + 80i64);
      Scaleform::GFx::AS3::ASVM::_constructInstance(v12, &pobj, v12->TextEventExClass.pObject, 3u, &argv);
      pObject = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)pobj.pObject;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pobj.pObject[1].16,
        pDispObj);
      String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                 (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)this[-1].pClassName + 4) + 360i64),
                 v21,
                 (const char *)(v8 + 12));
      Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(pObject, String);
      pNode = v21[0].pNode;
      v16 = v21[0].pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      LODWORD(pObject[1].vfptr) = controllerIndex;
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)pDispObj,
        pObject,
        (Scaleform::GFx::DisplayObject *)this[-1].pClassName);
      `eh vector destructor iterator(
        &argv,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)((char *)pObject - 1);
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
    v18 = result.pNode;
    v16 = result.pNode->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
}

// File Line: 197
// RVA: 0x802E70
__int64 __fastcall Scaleform::GFx::AS3::AvmTextField::OnCharEvent(
        Scaleform::GFx::AS3::AvmTextField *this,
        wchar_t wcharCode,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AvmDisplayObjBaseVtbl *vfptr; // rbx
  __int64 CaretIndex; // rax
  wchar_t v8; // [rsp+48h] [rbp+10h] BYREF

  v8 = wcharCode;
  vfptr = this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr;
  CaretIndex = Scaleform::GFx::TextField::GetCaretIndex((Scaleform::GFx::TextField *)this[-1].pClassName);
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS3::AvmTextField *, __int64, __int64, wchar_t *, unsigned int))vfptr[2].ToAvmDispContainerBase)(
           this,
           CaretIndex,
           1i64,
           &v8,
           controllerIdx);
}

// File Line: 203
// RVA: 0x8038A0
void __fastcall Scaleform::GFx::AS3::AvmTextField::OnEventLoad(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // rbx
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  char *v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rcx
  Scaleform::GFx::InteractiveObject *v7; // rax
  __int64 v8; // rdx
  Scaleform::GFx::InteractiveObject *v9; // rbx
  unsigned int Flags; // ecx
  int v11; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rdx

  pDispObj = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  pParent = pDispObj->pParent;
  if ( pParent
    && (v4 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset,
        (v5 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 8i64))(v4)) != 0) )
  {
    v6 = v5 - 56;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (Scaleform::GFx::InteractiveObject *)(*(__int64 (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v6 + 200i64))(
                                              v6,
                                              pDispObj);
  if ( v7 )
    Scaleform::GFx::InteractiveObject::InsertToPlayListAfter(pDispObj, v7);
  else
    Scaleform::GFx::InteractiveObject::AddToPlayList(pDispObj);
  v9 = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  Flags = v9->Flags;
  if ( (Flags & 0x200000) == 0 || (Flags & 0x400000) != 0 )
    v8 = 0i64;
  else
    LOBYTE(v8) = 1;
  v11 = (int)v9->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
               this->pDispObj,
               v8);
  if ( v11 == -1 )
  {
    v9->Flags |= 0x400000u;
  }
  else if ( v11 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v9);
  }
  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pAS3CollectiblePtr,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)pAS3RawPtr);
  this->pAS3RawPtr = 0i64;
}

// File Line: 228
// RVA: 0x7F9480
bool __fastcall Scaleform::GFx::AS3::AvmTextField::IsTabable(Scaleform::GFx::AS3::AvmTextField *this)
{
  bool result; // al
  Scaleform::GFx::TextField *v3; // rcx

  result = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
                                             + 472i64))(*(_QWORD *)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags);
  if ( result )
  {
    v3 = *(Scaleform::GFx::TextField **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags;
    if ( (v3->Scaleform::GFx::InteractiveObject::Flags & 0x60) != 0 )
      return (v3->Scaleform::GFx::InteractiveObject::Flags & 0x60) == 96;
    else
      return v3->TabIndex > 0 || !Scaleform::GFx::TextField::IsReadOnly(v3);
  }
  return result;
}

// File Line: 241
// RVA: 0x802650
void __fastcall Scaleform::GFx::AS3::AvmTextField::NotifyChanged(Scaleform::GFx::AS3::AvmTextField *this)
{
  const char *pClassName; // rax
  Scaleform::GFx::ASString *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pDispObj; // rbx
  Scaleform::GFx::DisplayObject *v5; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v7; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> result; // [rsp+50h] [rbp+8h] BYREF

  pClassName = this[-1].pClassName;
  v3 = (Scaleform::GFx::ASString *)(*((_QWORD *)pClassName + 4) + 856i64);
  pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  if ( !pDispObj )
    pDispObj = this[-1].pAS3RawPtr;
  if ( ((unsigned __int8)pDispObj & 1) != 0 )
    pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pDispObj - 1);
  if ( pDispObj
    && (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
          pDispObj,
          (Scaleform::GFx::ASString *)(*((_QWORD *)pClassName + 4) + 856i64),
          0)
     || Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(pDispObj, v3, 1)) )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      pDispObj,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
      v3,
      1,
      0);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)pDispObj);
    v5 = (Scaleform::GFx::DisplayObject *)this[-1].pClassName;
    pObject = result.pObject;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)pDispObj);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(pDispObj, pObject, v5);
    v7 = result.pObject;
    if ( result.pObject )
    {
      if ( ((__int64)result.pObject & 1) != 0 )
      {
        --result.pObject;
      }
      else
      {
        RefCount = result.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          result.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
  }
}

// File Line: 255
// RVA: 0x805560
void __fastcall Scaleform::GFx::AS3::AvmTextField::OnScroll(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::ASString *v2; // r14
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pDispObj; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rsi
  __int64 v6; // rax
  unsigned __int64 *v7; // rax
  char *v8; // rax
  Scaleform::GFx::DisplayObject *pClassName; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v10; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v11; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> result; // [rsp+50h] [rbp+8h] BYREF

  v2 = (Scaleform::GFx::ASString *)*((_QWORD *)this[-1].pClassName + 4);
  pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  if ( !pDispObj )
    pDispObj = this[-1].pAS3RawPtr;
  if ( ((unsigned __int8)pDispObj & 1) != 0 )
    pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pDispObj - 1);
  if ( pDispObj )
  {
    pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)pDispObj->pImpl.pObject;
    if ( pObject )
    {
      pTable = pObject[1].pTable;
      if ( pTable )
      {
        v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               pObject + 1,
               v2 + 108,
               v2[108].pNode->HashFlags & pTable->SizeMask);
        if ( v6 >= 0 )
        {
          v7 = &pTable[1].SizeMask + 3 * v6;
          if ( v7 )
          {
            v8 = (char *)(v7 + 1);
            if ( v8 )
            {
              if ( *(_QWORD *)v8 )
              {
                if ( *(_QWORD *)(*(_QWORD *)v8 + 8i64) )
                {
                  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
                    pDispObj,
                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
                    v2 + 108,
                    1,
                    0);
                  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
                    (Scaleform::GFx::AS3::Instances::fl::XMLList *)pDispObj);
                  pClassName = (Scaleform::GFx::DisplayObject *)this[-1].pClassName;
                  v10 = result.pObject;
                  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
                    (Scaleform::GFx::AS3::Instances::fl::XMLList *)pDispObj);
                  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(pDispObj, v10, pClassName);
                  v11 = result.pObject;
                  if ( result.pObject )
                  {
                    if ( ((__int64)result.pObject & 1) != 0 )
                    {
                      --result.pObject;
                    }
                    else
                    {
                      RefCount = result.pObject->RefCount;
                      if ( (RefCount & 0x3FFFFF) != 0 )
                      {
                        result.pObject->RefCount = RefCount - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 269
// RVA: 0x802F40
char __fastcall Scaleform::GFx::AS3::AvmTextField::OnEditorInsertingText(
        Scaleform::GFx::AS3::AvmTextField *this,
        unsigned __int64 pos,
        unsigned __int64 len,
        const wchar_t *wstr,
        unsigned int controllerIdx)
{
  Scaleform::GFx::ASString *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pDispObj; // rdi
  Scaleform::GFx::AS3::Value::V1U pNode; // rcx
  Scaleform::GFx::AS3::ASVM *v10; // rsi
  Scaleform::GFx::AS3::Object **p_pObject; // r8
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *pObject; // rbx
  Scaleform::GFx::DisplayObject *pClassName; // rsi
  bool v14; // di
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value::VU v17; // [rsp+38h] [rbp-90h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-78h] BYREF
  int v19; // [rsp+70h] [rbp-58h]
  __int64 v20; // [rsp+78h] [rbp-50h]
  char v21; // [rsp+80h] [rbp-48h]
  int v22; // [rsp+90h] [rbp-38h]
  __int64 v23; // [rsp+98h] [rbp-30h]
  char v24; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+D0h] [rbp+8h] BYREF

  v7 = (Scaleform::GFx::ASString *)*((_QWORD *)this[-1].pClassName + 4);
  pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  if ( !pDispObj )
    pDispObj = this[-1].pAS3RawPtr;
  if ( ((unsigned __int8)pDispObj & 1) != 0 )
    pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pDispObj - 1);
  if ( !pDispObj
    || !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(pDispObj, v7 + 106, 0)
    && !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(pDispObj, v7 + 106, 1) )
  {
    return 1;
  }
  pobj.pObject = 0i64;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  pNode = (Scaleform::GFx::AS3::Value::V1U)v7[106].pNode;
  ptr.value.VS._1 = pNode;
  if ( pNode.VStr == &pNode.VStr->pManager->NullStringNode )
  {
    v17.VS._1.VStr = 0i64;
    ptr.value = v17;
    ptr.Flags = 12;
  }
  else
  {
    ++pNode.VStr->RefCount;
  }
  v19 = 1;
  v20 = 0i64;
  v21 = 1;
  v22 = 1;
  v23 = 0i64;
  v24 = 1;
  v10 = *(Scaleform::GFx::AS3::ASVM **)(*((_QWORD *)this[-1].pClassName + 4) + 80i64);
  p_pObject = &v10->TextEventExClass.pObject;
  if ( !v10->ExtensionsEnabled )
    p_pObject = &v10->TextEventClass.pObject;
  Scaleform::GFx::AS3::ASVM::_constructInstance(v10, &pobj, *p_pObject, 3u, &ptr);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)pobj.pObject;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pobj.pObject[1].16,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)pDispObj);
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(pObject, wstr);
  if ( v10->ExtensionsEnabled )
    LODWORD(pObject[1].vfptr) = controllerIdx;
  pClassName = (Scaleform::GFx::DisplayObject *)this[-1].pClassName;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)pDispObj);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(pDispObj, pObject, pClassName);
  v14 = (*((_BYTE *)&pObject->Scaleform::GFx::AS3::Instances::fl_events::Event + 84) & 4) == 0;
  `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( ((unsigned __int8)pObject & 1) != 0 )
  {
    pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)((char *)pObject - 1);
    return v14;
  }
  RefCount = pObject->RefCount;
  if ( (RefCount & 0x3FFFFF) == 0 )
    return v14;
  pObject->RefCount = RefCount - 1;
  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
  return v14;
}

// File Line: 306
// RVA: 0x807F50
void __fastcall Scaleform::GFx::AS3::AvmTextField::ProceedImageSubstitution(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::AS3::VM *vm,
        int idx,
        Scaleform::GFx::AS3::Value *ve)
{
  double VNumber; // r12
  Scaleform::Render::Text::ImageDesc *v6; // rdi
  Scaleform::GFx::AS3::Value::V1U *v7; // rax
  char v8; // si
  Scaleform::GFx::AS3::Value::V1U v9; // rbx
  Scaleform::GFx::AS3::Value::V2U v10; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdx
  int v12; // r14d
  const char *pData; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned __int64 Length; // rbx
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  float v24; // xmm8_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm12_4
  float v28; // xmm11_4
  Scaleform::GFx::ASStringNode *pImage; // rbx
  Scaleform::GFx::AS3::Value::V1U *ConstString; // rax
  char v31; // r14
  Scaleform::GFx::AS3::Value::V1U v32; // rsi
  Scaleform::GFx::AS3::Value::V2U v33; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v34; // rcx
  int v35; // r15d
  const char *v36; // rax
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::ImageResource *ImageResource; // r14
  Scaleform::GFx::AS2::AvmCharacter *v42; // r15
  Scaleform::GFx::Resource *v43; // rax
  Scaleform::GFx::Resource *v44; // rsi
  bool v45; // r15
  Scaleform::MemoryHeap *v46; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *ImageCreator; // rax
  Scaleform::GFx::ASString *v48; // rax
  Scaleform::GFx::ASStringNode *v49; // rcx
  Scaleform::GFx::AS3::Value::V1U *v50; // rax
  char v51; // r8
  Scaleform::GFx::AS3::Value::V1U v52; // rsi
  Scaleform::GFx::AS3::Value::V2U v53; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v54; // rcx
  int v55; // ecx
  const char *v56; // rax
  Scaleform::GFx::ASString *v57; // rax
  Scaleform::GFx::ASStringNode *v58; // rcx
  Scaleform::GFx::ASStringNode *v59; // rcx
  Scaleform::GFx::ASStringNode *v60; // rcx
  long double v61; // r14
  Scaleform::GFx::ASString *v62; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v63; // rcx
  Scaleform::GFx::AS3::Value::V1U v64; // rsi
  const char *v65; // rax
  Scaleform::GFx::ASStringNode *v66; // rcx
  Scaleform::GFx::ASString *v67; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v68; // rcx
  Scaleform::GFx::AS3::Value::V1U v69; // rsi
  const char *v70; // rax
  Scaleform::GFx::ASStringNode *v71; // rcx
  Scaleform::GFx::ASString *v72; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v73; // rcx
  Scaleform::GFx::AS3::Value::V1U v74; // rsi
  const char *v75; // rax
  Scaleform::GFx::ASStringNode *v76; // rcx
  float v77; // xmm6_4
  Scaleform::GFx::ASString *v78; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v79; // rcx
  Scaleform::GFx::AS3::Value::V1U v80; // rsi
  const char *v81; // rax
  Scaleform::GFx::ASStringNode *v82; // rcx
  char *v83; // rsi
  Scaleform::GFx::TextField *v84; // r14
  Scaleform::GFx::ASStringNode *v85; // rax
  Scaleform::Render::Text::ImageDesc *v86; // rax
  Scaleform::Render::Image *v87; // rcx
  Scaleform::Render::Text::ImageDesc *v88; // rax
  int v89; // xmm2_4
  Scaleform::GFx::ASString *v90; // rax
  Scaleform::GFx::ASStringNode *v91; // rcx
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASString v93; // [rsp+20h] [rbp-A8h] BYREF
  long double v94; // [rsp+28h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::Value p; // [rsp+30h] [rbp-98h] BYREF
  Scaleform::MemAddressStub *adr; // [rsp+50h] [rbp-78h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp-70h] BYREF
  __int64 v98; // [rsp+60h] [rbp-68h]
  Scaleform::GFx::AS3::Value v; // [rsp+68h] [rbp-60h] BYREF
  __int64 v100; // [rsp+88h] [rbp-40h]
  Scaleform::GFx::AS3::Value::V1U v101; // [rsp+90h] [rbp-38h]
  Scaleform::GFx::AS3::Value::V2U v102; // [rsp+98h] [rbp-30h]
  Scaleform::GFx::AS3::Multiname v103; // [rsp+A0h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::Multiname v104; // [rsp+D0h] [rbp+8h] BYREF
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element pbuff; // [rsp+100h] [rbp+38h] BYREF
  Scaleform::GFx::AS3::Multiname v106; // [rsp+138h] [rbp+70h] BYREF
  Scaleform::GFx::AS3::Multiname v107; // [rsp+168h] [rbp+A0h] BYREF
  Scaleform::GFx::AS3::Multiname v108; // [rsp+198h] [rbp+D0h] BYREF
  Scaleform::MemAddressStub *v109; // [rsp+1C8h] [rbp+100h]
  Scaleform::GFx::AS3::Value::V2U v110; // [rsp+1D0h] [rbp+108h]
  Scaleform::GFx::AS3::Multiname v111; // [rsp+1D8h] [rbp+110h] BYREF
  char *v112; // [rsp+208h] [rbp+140h]
  Scaleform::Render::Text::DocView::ImageSubstitutor *ImageSubstitutor; // [rsp+210h] [rbp+148h]
  __int64 v114; // [rsp+218h] [rbp+150h]
  Scaleform::StringBuffer v115; // [rsp+220h] [rbp+158h] BYREF
  Scaleform::GFx::AS2::AvmCharacter *v116; // [rsp+2F8h] [rbp+230h]
  unsigned int v117; // [rsp+308h] [rbp+240h]
  Scaleform::GFx::ASString v118; // [rsp+310h] [rbp+248h] BYREF

  v114 = -2i64;
  if ( (ve->Flags & 0x1F) - 12 > 3 )
    return;
  adr = (Scaleform::MemAddressStub *)this->pDispObj;
  v109 = adr;
  VNumber = ve->value.VNumber;
  v94 = VNumber;
  v6 = 0i64;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0i64;
  ImageSubstitutor = Scaleform::GFx::TextField::CreateImageSubstitutor((Scaleform::GFx::TextField *)adr);
  if ( !ImageSubstitutor )
    goto LABEL_196;
  pbuff.pImageDesc.pObject = 0i64;
  v7 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                            vm->StringManagerRef,
                                            &result,
                                            "subString");
  v8 = 10;
  p.Flags = 10;
  p.Bonus.pWeakProxy = 0i64;
  v9 = *v7;
  p.value.VS._1 = v9;
  if ( v9.VStr == &v9.VStr->pManager->NullStringNode )
  {
    v9.VStr = 0i64;
    p.value.VS._1.VStr = 0i64;
    v10.VObj = v110.VObj;
    p.value.VS._2 = v110;
    v8 = 12;
    p.Flags = 12;
  }
  else
  {
    ++v9.VStr->RefCount;
    v10.VObj = (Scaleform::GFx::AS3::Object *)p.value.VS._2;
  }
  pObject = vm->PublicNamespace.pObject;
  v103.Kind = MN_QName;
  v103.Obj.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  v103.Name.Flags = 0;
  v103.Name.Bonus.pWeakProxy = 0i64;
  v12 = v8 & 0x1F;
  if ( (unsigned int)(v12 - 12) <= 3
    && v9.VStr
    && (pData = v9.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v103.Name, (Scaleform::GFx::ASString *)&v9.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v103.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v9.VStr[1].RefCount);
    v103.Kind &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&p, 2);
    *(_QWORD *)&v103.Name.Flags = *(_QWORD *)&p.Flags;
    v103.Name.Bonus.pWeakProxy = 0i64;
    v103.Name.value.VS._1 = v9;
    v103.Name.value.VS._2 = v10;
    if ( (v8 & 0x1Fu) > 9 )
    {
      if ( v12 == 10 )
      {
        ++v9.VStr->RefCount;
      }
      else if ( (v8 & 0x1Fu) <= 0xF )
      {
        if ( v9.VStr )
          v9.VStr->Size = (v9.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v8 & 0x1Fu) <= 0x11 && v10.VObj )
      {
        v10.VObj->RefCount = (v10.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (v103.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v103.Name, &v118);
      if ( v118.pNode->Size )
      {
        if ( *v118.pNode->pData == 64 )
        {
          v103.Kind |= 8u;
          v14 = Scaleform::GFx::ASString::Substring(&v118, &v93, 1, v118.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v103.Name, v14);
          pNode = v93.pNode;
          v16 = v93.pNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
      v17 = v118.pNode;
      v16 = v118.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  if ( (v8 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&p);
  v18 = result.pNode;
  v16 = result.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( !*(_BYTE *)(*(__int64 (__fastcall **)(double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&VNumber + 32i64))(
                    COERCE_DOUBLE(*(_QWORD *)&VNumber),
                    &v118,
                    &v103,
                    &v) )
  {
    Name = Scaleform::GFx::AS3::AvmDisplayObj::GetName(v116, &v118);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&adr[24],
      "%s.setImageSubstitutions() failed for #%d element - subString should be specified",
      Name->pNode->pData,
      v117);
    v22 = v118.pNode;
LABEL_192:
    v16 = v22->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
LABEL_194:
    Scaleform::GFx::AS3::Multiname::~Multiname(&v103);
    if ( pbuff.pImageDesc.pObject )
      Scaleform::RefCountNTSImpl::Release(pbuff.pImageDesc.pObject);
LABEL_196:
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        v16 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v16 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v.Bonus.pWeakProxy = 0i64;
        v.value.VS._1.VStr = 0i64;
        p.value.VS._2.VObj = 0i64;
        v.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
    }
    return;
  }
  Scaleform::GFx::AS3::Value::ToStringValue(&v, (Scaleform::GFx::AS3::CheckResult *)&v118, vm->StringManagerRef);
  v93.pNode = v.value.VS._1.VStr;
  ++v.value.VS._1.VStr->RefCount;
  Length = Scaleform::GFx::ASConstString::GetLength(&v93);
  if ( Length > 0xF )
  {
    v20 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(v116, &v118);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&adr[24],
      "%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters",
      v20->pNode->pData,
      v117);
    v21 = v118.pNode;
    v16 = v118.pNode->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    v22 = v93.pNode;
    goto LABEL_192;
  }
  Scaleform::UTF8Util::DecodeStringSafe(pbuff.SubString, 0x14ui64, v93.pNode->pData, v93.pNode->Size + 1);
  pbuff.SubStringLen = Length;
  v23 = v93.pNode;
  v16 = v93.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  v24 = 0.0;
  v25 = 0.0;
  v26 = 0.0;
  v27 = 0.0;
  v28 = 0.0;
  v112 = 0i64;
  pImage = 0i64;
  v93.pNode = 0i64;
  ConstString = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                                     vm->StringManagerRef,
                                                     (Scaleform::GFx::ASString *)&v,
                                                     "image");
  v31 = 10;
  p.Flags = 10;
  p.Bonus.pWeakProxy = 0i64;
  v32 = *ConstString;
  p.value.VS._1 = v32;
  if ( v32.VStr == &v32.VStr->pManager->NullStringNode )
  {
    v32.VStr = 0i64;
    p.value.VS._1.VStr = 0i64;
    v33.VObj = v110.VObj;
    p.value.VS._2 = v110;
    v31 = 12;
    p.Flags = 12;
  }
  else
  {
    ++v32.VStr->RefCount;
    v33.VObj = (Scaleform::GFx::AS3::Object *)p.value.VS._2;
  }
  v34 = vm->PublicNamespace.pObject;
  LODWORD(v.Bonus.pWeakProxy) = 0;
  v.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v34;
  if ( v34 )
    v34->RefCount = (v34->RefCount + 1) & 0x8FBFFFFF;
  LODWORD(v.value.VS._2.VObj) = 0;
  v100 = 0i64;
  v35 = v31 & 0x1F;
  if ( (unsigned int)(v35 - 12) <= 3
    && v32.VStr
    && (v36 = v32.VStr[1].pData, *((_DWORD *)v36 + 30) == 17)
    && (v36[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(
      (Scaleform::GFx::AS3::Value *)&v.value.VS._2,
      (Scaleform::GFx::ASString *)&v32.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v.value,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v32.VStr[1].RefCount);
    LODWORD(v.Bonus.pWeakProxy) &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&p, 2);
    v.value.VS._2.VObj = *(Scaleform::GFx::AS3::Object **)&p.Flags;
    v100 = 0i64;
    v101 = v32;
    v102.VObj = v33.VObj;
    if ( (v31 & 0x1Fu) > 9 )
    {
      if ( v35 == 10 )
      {
        ++v32.VStr->RefCount;
      }
      else if ( (v31 & 0x1Fu) <= 0xF )
      {
        if ( v32.VStr )
          v32.VStr->Size = (v32.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v31 & 0x1Fu) <= 0x11 && v33.VObj )
      {
        v33.VObj->RefCount = (v33.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( ((__int64)v.value.VS._2.VObj & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString((Scaleform::GFx::AS3::Value *)&v.value.VS._2, &v118);
      if ( v118.pNode->Size )
      {
        if ( *v118.pNode->pData == 64 )
        {
          LODWORD(v.Bonus.pWeakProxy) |= 8u;
          v37 = Scaleform::GFx::ASString::Substring(&v118, &result, 1, v118.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)&v.value.VS._2, v37);
          v38 = result.pNode;
          v16 = result.pNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v38);
        }
      }
      v39 = v118.pNode;
      v16 = v118.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v39);
    }
  }
  if ( (v31 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&p);
  v40 = *(Scaleform::GFx::ASStringNode **)&v.Flags;
  v16 = (*(_DWORD *)(*(_QWORD *)&v.Flags + 24i64))-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  if ( !*(_BYTE *)(*(__int64 (__fastcall **)(double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Value::Extra *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::ASStringNode *))(**(_QWORD **)&VNumber + 32i64))(
                    COERCE_DOUBLE(*(_QWORD *)&VNumber),
                    &v118,
                    &v.Bonus,
                    &v,
                    v93.pNode)
    || !Scaleform::GFx::AS3::VM::IsOfType(vm, &v, "flash.display.BitmapData", vm->CurrentDomain.pObject) )
  {
    goto LABEL_187;
  }
  ImageResource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource((Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v.value.VS._1.VStr);
  v42 = v116;
  v43 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v116->pDispObj->vfptr[66].__vecDelDtor)(v116->pDispObj);
  v44 = v43;
  if ( v43 )
    Scaleform::Render::RenderBuffer::AddRef(v43);
  *(_QWORD *)&v.Flags = v44;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))ImageResource->pImage->vfptr[3].__vecDelDtor)(ImageResource->pImage) )
  {
    pImage = (Scaleform::GFx::ASStringNode *)ImageResource->pImage;
    if ( pImage )
      (*((void (__fastcall **)(Scaleform::Render::ImageBase *))pImage->pData + 1))(ImageResource->pImage);
    v93.pNode = pImage;
  }
  else
  {
    v45 = Scaleform::GFx::StateBag::GetImageCreator(
            (Scaleform::GFx::StateBag *)&v44[1],
            (Scaleform::Ptr<Scaleform::GFx::ImageCreator> *)&v118)->pObject == 0i64;
    if ( v118.pNode )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v118.pNode);
    if ( v45 )
    {
      LODWORD(v118.pNode) = 135168;
      Scaleform::LogDebugMessage((Scaleform::LogMessageId)&v118, "ImageCreator is null in ProceedImageSubstitution");
      goto LABEL_91;
    }
    v42 = v116;
    v46 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v116);
    p.Flags = 3;
    p.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v46;
    p.value = (Scaleform::GFx::AS3::Value::VU)0x100000001ui64;
    adr = 0i64;
    result.pNode = 0i64;
    v98 = 0i64;
    ImageCreator = Scaleform::GFx::StateBag::GetImageCreator(
                     (Scaleform::GFx::StateBag *)&v44[1],
                     (Scaleform::Ptr<Scaleform::GFx::ImageCreator> *)&v118);
    pImage = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, Scaleform::GFx::AS3::Value *, Scaleform::Render::ImageBase *))ImageCreator->pObject->vfptr[4].__vecDelDtor)(
                                               ImageCreator->pObject,
                                               &p,
                                               ImageResource->pImage);
    v93.pNode = pImage;
    if ( v118.pNode )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v118.pNode);
  }
  if ( pImage )
  {
    (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::ASString *))pImage->pData + 6))(
      pImage,
      &result);
    v27 = (float)(v98 - LODWORD(result.pNode));
    v28 = (float)(HIDWORD(v98) - HIDWORD(result.pNode));
    v25 = v27 * 20.0;
    v26 = v28 * 20.0;
    if ( v27 == 0.0 || v28 == 0.0 )
    {
      v48 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(v42, &v118);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&adr[24],
        "%s.setImageSubstitutions() failed for #%d element - image has one zero dimension",
        v48->pNode->pData,
        v117);
      v49 = v118.pNode;
      v16 = v118.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v49);
      if ( v44 )
        Scaleform::GFx::Resource::Release(v44);
LABEL_189:
      Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&v.Bonus);
      if ( pImage )
        (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))pImage->pData + 2))(pImage);
      goto LABEL_194;
    }
  }
LABEL_91:
  if ( v44 )
    Scaleform::GFx::Resource::Release(v44);
  if ( !pImage )
  {
LABEL_187:
    v90 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(v116, &v118);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&adr[24],
      "%s.setImageSubstitutions() failed for #%d element - image is not specified or not a BitmapData",
      v90->pNode->pData,
      v117);
    v91 = v118.pNode;
    v16 = v118.pNode->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v91);
    goto LABEL_189;
  }
  v50 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                             vm->StringManagerRef,
                                             &result,
                                             "width");
  v51 = 10;
  p.Flags = 10;
  p.Bonus.pWeakProxy = 0i64;
  v52 = *v50;
  p.value.VS._1 = v52;
  if ( v52.VStr == &v52.VStr->pManager->NullStringNode )
  {
    v52.VStr = 0i64;
    p.value.VS._1.VStr = 0i64;
    v53.VObj = v110.VObj;
    p.value.VS._2 = v110;
    v51 = 12;
    p.Flags = 12;
  }
  else
  {
    ++v52.VStr->RefCount;
    v53.VObj = (Scaleform::GFx::AS3::Object *)p.value.VS._2;
  }
  v54 = vm->PublicNamespace.pObject;
  v104.Kind = MN_QName;
  v104.Obj.pObject = v54;
  if ( v54 )
    v54->RefCount = (v54->RefCount + 1) & 0x8FBFFFFF;
  v104.Name.Flags = 0;
  v104.Name.Bonus.pWeakProxy = 0i64;
  v55 = v51 & 0x1F;
  if ( (unsigned int)(v55 - 12) <= 3
    && v52.VStr
    && (v56 = v52.VStr[1].pData, *((_DWORD *)v56 + 30) == 17)
    && (v56[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v104.Name, (Scaleform::GFx::ASString *)&v52.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v104.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v52.VStr[1].RefCount);
    v104.Kind &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&p, 2);
    *(_QWORD *)&v104.Name.Flags = *(_QWORD *)&p.Flags;
    v104.Name.Bonus.pWeakProxy = 0i64;
    v104.Name.value.VS._1 = v52;
    v104.Name.value.VS._2 = v53;
    if ( (v51 & 0x1Fu) > 9 )
    {
      if ( v55 == 10 )
      {
        ++v52.VStr->RefCount;
      }
      else if ( (v51 & 0x1Fu) <= 0xF )
      {
        if ( v52.VStr )
          v52.VStr->Size = (v52.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v51 & 0x1Fu) <= 0x11 && v53.VObj )
      {
        v53.VObj->RefCount = (v53.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (v104.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v104.Name, &v118);
      if ( v118.pNode->Size )
      {
        if ( *v118.pNode->pData == 64 )
        {
          v104.Kind |= 8u;
          v57 = Scaleform::GFx::ASString::Substring(&v118, (Scaleform::GFx::ASString *)&v, 1, v118.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v104.Name, v57);
          v58 = *(Scaleform::GFx::ASStringNode **)&v.Flags;
          v16 = (*(_DWORD *)(*(_QWORD *)&v.Flags + 24i64))-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v58);
        }
      }
      v59 = v118.pNode;
      v16 = v118.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v59);
    }
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v60 = result.pNode;
  v16 = result.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v60);
  v61 = v94;
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(_QWORD, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::ASStringNode *))(**(_QWORD **)&v94 + 32i64))(
                   *(_QWORD *)&v94,
                   &v118,
                   &v104,
                   &v,
                   v93.pNode) )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(&v, (Scaleform::GFx::AS3::CheckResult *)&v118, &v94);
    v25 = v94 * 20.0;
  }
  v62 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          vm->StringManagerRef,
          &v118,
          "height");
  Scaleform::GFx::AS3::Value::Value(&p, v62);
  v63 = vm->PublicNamespace.pObject;
  v111.Kind = MN_QName;
  v111.Obj.pObject = v63;
  if ( v63 )
    v63->RefCount = (v63->RefCount + 1) & 0x8FBFFFFF;
  v111.Name.Flags = 0;
  v111.Name.Bonus.pWeakProxy = 0i64;
  if ( (p.Flags & 0x1F) - 12 <= 3
    && (v64 = p.value.VS._1, p.value.VS._1.VStr)
    && (v65 = p.value.VS._1.VStr[1].pData, *((_DWORD *)v65 + 30) == 17)
    && (v65[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v111.Name, (Scaleform::GFx::ASString *)&p.value.VS._1.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v111.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v64.VStr[1].RefCount);
    v111.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v111.Name, &p);
    Scaleform::GFx::AS3::Multiname::PostProcessName(&v111, 0);
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v66 = v118.pNode;
  v16 = v118.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v66);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v61 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v61),
                   &v118,
                   &v111,
                   &v) )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(&v, (Scaleform::GFx::AS3::CheckResult *)&v118, &v94);
    v26 = v94 * 20.0;
  }
  v67 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          vm->StringManagerRef,
          &v118,
          "baseLineX");
  Scaleform::GFx::AS3::Value::Value(&p, v67);
  v68 = vm->PublicNamespace.pObject;
  v108.Kind = MN_QName;
  v108.Obj.pObject = v68;
  if ( v68 )
    v68->RefCount = (v68->RefCount + 1) & 0x8FBFFFFF;
  v108.Name.Flags = 0;
  v108.Name.Bonus.pWeakProxy = 0i64;
  if ( (p.Flags & 0x1F) - 12 <= 3
    && (v69 = p.value.VS._1, p.value.VS._1.VStr)
    && (v70 = p.value.VS._1.VStr[1].pData, *((_DWORD *)v70 + 30) == 17)
    && (v70[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v108.Name, (Scaleform::GFx::ASString *)&p.value.VS._1.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v108.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v69.VStr[1].RefCount);
    v108.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v108.Name, &p);
    Scaleform::GFx::AS3::Multiname::PostProcessName(&v108, 0);
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v71 = v118.pNode;
  v16 = v118.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v71);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v61 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v61),
                   &v118,
                   &v108,
                   &v) )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(&v, (Scaleform::GFx::AS3::CheckResult *)&v118, &v94);
    v24 = v94 * 20.0;
  }
  v72 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          vm->StringManagerRef,
          &v118,
          "baseLineY");
  Scaleform::GFx::AS3::Value::Value(&p, v72);
  v73 = vm->PublicNamespace.pObject;
  v107.Kind = MN_QName;
  v107.Obj.pObject = v73;
  if ( v73 )
    v73->RefCount = (v73->RefCount + 1) & 0x8FBFFFFF;
  v107.Name.Flags = 0;
  v107.Name.Bonus.pWeakProxy = 0i64;
  if ( (p.Flags & 0x1F) - 12 <= 3
    && (v74 = p.value.VS._1, p.value.VS._1.VStr)
    && (v75 = p.value.VS._1.VStr[1].pData, *((_DWORD *)v75 + 30) == 17)
    && (v75[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v107.Name, (Scaleform::GFx::ASString *)&p.value.VS._1.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v107.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v74.VStr[1].RefCount);
    v107.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v107.Name, &p);
    Scaleform::GFx::AS3::Multiname::PostProcessName(&v107, 0);
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v76 = v118.pNode;
  v16 = v118.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v76);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v61 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v61),
                   &v118,
                   &v107,
                   &v) )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(&v, (Scaleform::GFx::AS3::CheckResult *)&v118, &v94);
    v77 = v94 * 20.0;
  }
  else
  {
    v77 = v28 - 20.0;
  }
  v78 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          vm->StringManagerRef,
          &v118,
          "id");
  Scaleform::GFx::AS3::Value::Value(&p, v78);
  v79 = vm->PublicNamespace.pObject;
  v106.Kind = MN_QName;
  v106.Obj.pObject = v79;
  if ( v79 )
    v79->RefCount = (v79->RefCount + 1) & 0x8FBFFFFF;
  v106.Name.Flags = 0;
  v106.Name.Bonus.pWeakProxy = 0i64;
  if ( (p.Flags & 0x1F) - 12 <= 3
    && (v80 = p.value.VS._1, p.value.VS._1.VStr)
    && (v81 = p.value.VS._1.VStr[1].pData, *((_DWORD *)v81 + 30) == 17)
    && (v81[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v106.Name, (Scaleform::GFx::ASString *)&p.value.VS._1.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v106.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v80.VStr[1].RefCount);
    v106.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v106.Name, &p);
    Scaleform::GFx::AS3::Multiname::PostProcessName(&v106, 0);
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v82 = v118.pNode;
  v16 = v118.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v82);
  Scaleform::StringBuffer::StringBuffer(&v115, Scaleform::Memory::pGlobalHeap);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v61 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v61),
                   &v118,
                   &v106,
                   &v) )
  {
    Scaleform::GFx::AS3::Value::Convert2String(&v, (Scaleform::GFx::AS3::CheckResult *)&v118, &v115);
    v83 = &customCaption;
    if ( v115.pData )
      v83 = v115.pData;
  }
  else
  {
    v83 = v112;
  }
  v84 = (Scaleform::GFx::TextField *)adr;
  v85 = (Scaleform::GFx::ASStringNode *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::operator new(
                                          0x50ui64,
                                          adr);
  v118.pNode = v85;
  if ( v85 )
  {
    Scaleform::Render::Text::ImageDesc::ImageDesc((Scaleform::Render::Text::ImageDesc *)v85);
    v6 = v86;
  }
  if ( pbuff.pImageDesc.pObject )
    Scaleform::RefCountNTSImpl::Release(pbuff.pImageDesc.pObject);
  pbuff.pImageDesc.pObject = v6;
  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))pImage->pData + 1))(pImage);
  v87 = v6->pImage.pObject;
  if ( v87 )
    ((void (__fastcall *)(Scaleform::Render::Image *))v87->vfptr[2].__vecDelDtor)(v87);
  v6->pImage.pObject = (Scaleform::Render::Image *)pImage;
  pbuff.pImageDesc.pObject->BaseLineX = v24 * 0.050000001;
  pbuff.pImageDesc.pObject->BaseLineY = v77 * 0.050000001;
  pbuff.pImageDesc.pObject->ScreenWidth = v25;
  pbuff.pImageDesc.pObject->ScreenHeight = v26;
  if ( v83 )
    Scaleform::GFx::TextField::AddIdImageDescAssoc(v84, v83, pbuff.pImageDesc.pObject);
  v88 = pbuff.pImageDesc.pObject;
  v89 = LODWORD(pbuff.pImageDesc.pObject->BaseLineY) ^ _xmm[0];
  pbuff.pImageDesc.pObject->Matrix.M[0][3] = COERCE_FLOAT(LODWORD(pbuff.pImageDesc.pObject->BaseLineX) ^ _xmm[0])
                                           + pbuff.pImageDesc.pObject->Matrix.M[0][3];
  v88->Matrix.M[1][3] = *(float *)&v89 + v88->Matrix.M[1][3];
  Scaleform::Render::Matrix2x4<float>::AppendScaling(
    &pbuff.pImageDesc.pObject->Matrix,
    pbuff.pImageDesc.pObject->ScreenWidth / v27,
    pbuff.pImageDesc.pObject->ScreenHeight / v28);
  Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(ImageSubstitutor, &pbuff);
  v84->pDocument.pObject->RTFlags |= 2u;
  Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v116->pDispObj);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v115);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v106);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v107);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v108);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v111);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v104);
  Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&v.Bonus);
  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))pImage->pData + 2))(pImage);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v103);
  if ( pbuff.pImageDesc.pObject )
    Scaleform::RefCountNTSImpl::Release(pbuff.pImageDesc.pObject);
  Scaleform::GFx::AS3::Value::~Value(&v);
}

