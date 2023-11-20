// File Line: 29
// RVA: 0x77B250
void __fastcall Scaleform::GFx::AS3::AvmTextField::AvmTextField(Scaleform::GFx::AS3::AvmTextField *this, Scaleform::GFx::TextField *ptf)
{
  Scaleform::GFx::TextField *v2; // rbx
  Scaleform::GFx::AS3::AvmTextField *v3; // rdi
  Scaleform::GFx::AvmTextFieldBase *v4; // [rsp+50h] [rbp+18h]

  v2 = ptf;
  v3 = this;
  Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(
    (Scaleform::GFx::AS3::AvmInteractiveObj *)&this->vfptr,
    (Scaleform::GFx::InteractiveObject *)&ptf->vfptr);
  v4 = (Scaleform::GFx::AvmTextFieldBase *)&v3->vfptr;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable';
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmTextFieldBase::`vftable';
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmTextField::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmTextField::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmTextField::`vftable';
  v2->Flags |= 2u;
  Scaleform::GFx::TextField::SetSelection(v2, 0i64, 0i64);
}

// File Line: 66
// RVA: 0x804EB0
char __fastcall Scaleform::GFx::AS3::AvmTextField::OnMouseEvent(Scaleform::GFx::AS3::AvmTextField *this, Scaleform::GFx::EventId *event)
{
  Scaleform::GFx::EventId *v2; // r14
  Scaleform::GFx::AS3::AvmTextField *v3; // rsi
  Scaleform::GFx::TextField *v4; // rdi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // r12
  Scaleform::GFx::StateBag *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v9; // rdi
  Scaleform::GFx::AS3::ASVM *v10; // r15
  Scaleform::GFx::AS3::Object **v11; // r8
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  unsigned int v16; // eax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::UrlNavigator *v18; // rbx
  Scaleform::GFx::ASString v20[2]; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+40h] [rbp-49h]
  int v22; // [rsp+60h] [rbp-29h]
  __int64 v23; // [rsp+68h] [rbp-21h]
  char v24; // [rsp+70h] [rbp-19h]
  int v25; // [rsp+80h] [rbp-9h]
  __int64 v26; // [rsp+88h] [rbp-1h]
  char v27; // [rsp+90h] [rbp+7h]
  __int64 v28; // [rsp+A0h] [rbp+17h]
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+F8h] [rbp+6Fh]
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+100h] [rbp+77h]
  Scaleform::Render::Point<float> pPnt; // [rsp+108h] [rbp+7Fh]

  v28 = -2i64;
  v2 = event;
  v3 = this;
  Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent(
    (Scaleform::GFx::AS3::AvmInteractiveObj *)&this[-1].pAS3CollectiblePtr,
    event);
  if ( v2->Id != 16777228 )
    return 0;
  v4 = (Scaleform::GFx::TextField *)v3[-1].pClassName;
  v5 = Scaleform::GFx::TextField::GetBeginIndex((Scaleform::GFx::TextField *)v3[-1].pClassName);
  if ( v5 != Scaleform::GFx::TextField::GetEndIndex(v4) )
    return 0;
  if ( (v4->Flags >> 1) & 1 )
  {
    if ( v4->pDocument.pObject->pDocument.pObject->RTFlags & 1 )
    {
      if ( Scaleform::GFx::TextField::IsUrlUnderMouseCursor(v4, v2->ControllerIndex, &pPnt, 0i64) )
      {
        v6 = Scaleform::Render::Text::DocView::GetCharIndexAtPoint(v4->pDocument.pObject, pPnt.x, pPnt.y);
        if ( v6 != -1i64
          && Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
               (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->pDocument.pObject->vfptr,
               &ppdestTextFmt,
               0i64,
               v6)
          && Scaleform::Render::Text::TextFormat::IsUrlSet(ppdestTextFmt) )
        {
          v7 = ppdestTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
          v8 = *(Scaleform::GFx::StateBag **)(*((_QWORD *)v3[-1].pClassName + 4) + 16i64);
          if ( !v8 || Scaleform::String::CompareNoCase((const char *)(v7 + 12), "event:", 6i64) )
          {
            v18 = Scaleform::GFx::StateBag::GetUrlNavigator(
                    v8 + 2,
                    (Scaleform::Ptr<Scaleform::GFx::UrlNavigator> *)&result)->pObject;
            if ( result.pNode )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pNode);
            if ( v18 )
              v18->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, (unsigned int)&ppdestTextFmt->Url);
          }
          else
          {
            Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)v3[-1].pClassName + 4)
                                                                                                  + 360i64),
              &result,
              "link");
            v9 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3[-1].pDispObj;
            if ( !v9 )
              v9 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3[-1].pAS3RawPtr;
            if ( (unsigned __int8)v9 & 1 )
              v9 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v9 - 1);
            if ( v9
              && (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
                    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v9,
                    &result,
                    0)
               || Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
                    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v9,
                    &result,
                    1)) )
            {
              pobj.pObject = 0i64;
              ptr.Flags = 10;
              ptr.Bonus.pWeakProxy = 0i64;
              *(Scaleform::GFx::ASString *)&ptr.value.VNumber = result;
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
              v10 = *(Scaleform::GFx::AS3::ASVM **)(*((_QWORD *)v3[-1].pClassName + 4) + 80i64);
              v11 = (Scaleform::GFx::AS3::Object **)&v10->TextEventExClass;
              if ( !v10->ExtensionsEnabled )
                v11 = (Scaleform::GFx::AS3::Object **)&v10->TextEventClass;
              Scaleform::GFx::AS3::ASVM::_constructInstance(v10, &pobj, *v11, 3u, &ptr);
              v12 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)pobj.pObject;
              Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pobj.pObject[1].16,
                v9);
              v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)v3[-1].pClassName + 4) + 360i64),
                      v20,
                      (const char *)(v7 + 18));
              Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(v12, v13);
              v14 = v20[0].pNode;
              v15 = v20[0].pNode->RefCount == 1;
              --v14->RefCount;
              if ( v15 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v14);
              if ( v10->ExtensionsEnabled )
              {
                LODWORD(v12[1].vfptr) = v2->ControllerIndex;
                HIDWORD(v12[1].vfptr) = (unsigned __int8)v2->AsciiCode;
              }
              Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
                (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v9,
                (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v12->vfptr,
                (Scaleform::GFx::DisplayObject *)v3[-1].pClassName);
              `eh vector destructor iterator'(
                &ptr,
                0x20ui64,
                3,
                (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
              if ( v12 )
              {
                if ( (unsigned __int8)v12 & 1 )
                {
                  pobj.pObject = (Scaleform::GFx::AS3::Object *)((char *)&v12[-1].Text.pNode + 7);
                }
                else
                {
                  v16 = v12->RefCount;
                  if ( v16 & 0x3FFFFF )
                  {
                    v12->RefCount = v16 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
                  }
                }
              }
            }
            v17 = result.pNode;
            v15 = result.pNode->RefCount == 1;
            --v17->RefCount;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v17);
          }
        }
      }
    }
  }
  return 1;
}           --v17->RefCou

// File Line: 153
// RVA: 0x804BA0
void __fastcall Scaleform::GFx::AS3::AvmTextField::OnLinkEventEx(Scaleform::GFx::AS3::AvmTextField *this, Scaleform::GFx::TextField::LinkEvent event, unsigned int pos, unsigned int controllerIndex)
{
  unsigned int v4; // er15
  unsigned int v5; // edi
  Scaleform::GFx::TextField::LinkEvent v6; // ebx
  Scaleform::GFx::AS3::AvmTextField *v7; // rsi
  unsigned __int64 v8; // r14
  int v9; // ebx
  const char *v10; // r8
  Scaleform::GFx::AS3::Instances::fl::XMLList *v11; // rbx
  __int64 v12; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v13; // rdi
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+18h] [rbp-49h]
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+20h] [rbp-41h]
  Scaleform::GFx::ASString v21[2]; // [rsp+28h] [rbp-39h]
  Scaleform::GFx::AS3::Value argv; // [rsp+38h] [rbp-29h]
  int v23; // [rsp+58h] [rbp-9h]
  __int64 v24; // [rsp+60h] [rbp-1h]
  char v25; // [rsp+68h] [rbp+7h]
  int v26; // [rsp+78h] [rbp+17h]
  __int64 v27; // [rsp+80h] [rbp+1Fh]
  char v28; // [rsp+88h] [rbp+27h]
  __int64 v29; // [rsp+98h] [rbp+37h]
  Scaleform::GFx::ASString result; // [rsp+C8h] [rbp+67h]

  v29 = -2i64;
  v4 = controllerIndex;
  v5 = pos;
  v6 = event;
  v7 = this;
  (*(void (**)(void))(**((_QWORD **)this[-1].pClassName + 4) + 32i64))();
  if ( *(_BYTE *)(*(_QWORD *)(*((_QWORD *)v7[-1].pClassName + 4) + 80i64) + 976i64)
    && Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
         *(Scaleform::Render::Text::StyledText **)(*((_QWORD *)v7[-1].pClassName + 28) + 16i64),
         &ppdestTextFmt,
         0i64,
         v5)
    && ppdestTextFmt->PresentMask & 0x100
    && Scaleform::String::GetLength((Scaleform::String *)&ppdestTextFmt->Url.0) )
  {
    v8 = ppdestTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    v9 = v6 - 2;
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
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)v7[-1].pClassName
                                                                                            + 4)
                                                                                          + 360i64),
      &result,
      v10);
    v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7[-1].pDispObj;
    if ( !v11 )
      v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7[-1].pAS3RawPtr;
    if ( (unsigned __int8)v11 & 1 )
      v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v11 - 1);
    if ( v11
      && (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v11,
            &result,
            0)
       || Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v11,
            &result,
            1)) )
    {
      pobj.pObject = 0i64;
      argv.Flags = 10;
      argv.Bonus.pWeakProxy = 0i64;
      *(Scaleform::GFx::ASString *)&argv.value.VNumber = result;
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
      v12 = *(_QWORD *)(*((_QWORD *)v7[-1].pClassName + 4) + 80i64);
      ppdestTextFmt = (Scaleform::Render::Text::TextFormat *)&argv;
      Scaleform::GFx::AS3::ASVM::_constructInstance(
        (Scaleform::GFx::AS3::ASVM *)v12,
        &pobj,
        *(Scaleform::GFx::AS3::Object **)(v12 + 864),
        3u,
        &argv);
      v13 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)pobj.pObject;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pobj.pObject[1].16,
        v11);
      v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)v7[-1].pClassName + 4)
                                                                                                  + 360i64),
              v21,
              (const char *)(v8 + 12));
      Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(v13, v14);
      v15 = v21[0].pNode;
      v16 = v21[0].pNode->RefCount == 1;
      --v15->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      LODWORD(v13[1].vfptr) = v4;
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v11,
        (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v13->vfptr,
        (Scaleform::GFx::DisplayObject *)v7[-1].pClassName);
      `eh vector destructor iterator'(
        &argv,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      if ( (unsigned __int8)v13 & 1 )
      {
        pobj.pObject = (Scaleform::GFx::AS3::Object *)((char *)&v13[-1].Text.pNode + 7);
      }
      else
      {
        v17 = v13->RefCount;
        if ( v17 & 0x3FFFFF )
        {
          v13->RefCount = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
        }
      }
    }
    v18 = result.pNode;
    v16 = result.pNode->RefCount == 1;
    --v18->RefCount;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
}

// File Line: 197
// RVA: 0x802E70
__int64 __fastcall Scaleform::GFx::AS3::AvmTextField::OnCharEvent(Scaleform::GFx::AS3::AvmTextField *this, wchar_t wcharCode, unsigned int controllerIdx)
{
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v3; // rbx
  Scaleform::GFx::AS3::AvmTextField *v4; // rsi
  unsigned int v5; // edi
  __int64 v6; // rax
  unsigned int v7; // ST20_4
  wchar_t v9; // [rsp+48h] [rbp+10h]

  v9 = wcharCode;
  v3 = this->vfptr;
  v4 = this;
  v5 = controllerIdx;
  v6 = Scaleform::GFx::TextField::GetCaretIndex((Scaleform::GFx::TextField *)this[-1].pClassName);
  v7 = v5;
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS3::AvmTextField *, __int64, signed __int64, wchar_t *, unsigned int))v3[2].ToAvmDispContainerBase)(
           v4,
           v6,
           1i64,
           &v9,
           v7);
}

// File Line: 203
// RVA: 0x8038A0
void __fastcall Scaleform::GFx::AS3::AvmTextField::OnEventLoad(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rcx
  Scaleform::GFx::InteractiveObject *v6; // rax
  __int64 v7; // rdx
  Scaleform::GFx::InteractiveObject *v8; // rbx
  int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v10; // rdx

  v1 = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  v2 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)this;
  v3 = v1->pParent;
  if ( v3
    && (v4 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                         + 4 * (unsigned __int8)v3->AvmObjOffset))[1].__vecDelDtor)()) != 0 )
  {
    v5 = v4 - 56;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (Scaleform::GFx::InteractiveObject *)(*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v5 + 200i64))(
                                              v5,
                                              v1);
  if ( v6 )
    Scaleform::GFx::InteractiveObject::InsertToPlayListAfter(v1, v6);
  else
    Scaleform::GFx::InteractiveObject::AddToPlayList(v1);
  v8 = (Scaleform::GFx::InteractiveObject *)v2[3].pObject;
  if ( !((v8->Flags >> 21) & 1) || (v8->Flags >> 22) & 1 )
    v7 = 0i64;
  else
    LOBYTE(v7) = 1;
  v9 = (__int64)v8->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)v2[3].pObject, v7);
  if ( v9 == -1 )
  {
    v8->Flags |= 0x400000u;
  }
  else if ( v9 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v8);
  }
  v10 = v2[2].pObject;
  if ( !v10 )
    v10 = v2[1].pObject;
  if ( (unsigned __int8)v10 & 1 )
    v10 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v10 - 1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v2 + 1, v10);
  v2[2].pObject = 0i64;
}

// File Line: 228
// RVA: 0x7F9480
char __fastcall Scaleform::GFx::AS3::AvmTextField::IsTabable(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::AS3::AvmTextField *v1; // rbx
  char result; // al
  Scaleform::GFx::TextField *v3; // rcx

  v1 = this;
  result = (*(__int64 (**)(void))(**(_QWORD **)&this[-1].Flags + 472i64))();
  if ( result )
  {
    v3 = *(Scaleform::GFx::TextField **)&v1[-1].Flags;
    if ( v3->Flags & 0x60 )
    {
      result = (v3->Flags & 0x60) == 96;
    }
    else if ( v3->TabIndex <= 0 )
    {
      result = Scaleform::GFx::TextField::IsReadOnly(v3) == 0;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}

// File Line: 241
// RVA: 0x802650
void __fastcall Scaleform::GFx::AS3::AvmTextField::NotifyChanged(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::AS3::AvmTextField *v1; // rdi
  const char *v2; // rax
  Scaleform::GFx::ASString *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // rbx
  Scaleform::GFx::DisplayObject *v5; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v6; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> result; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = this[-1].pClassName;
  v3 = (Scaleform::GFx::ASString *)(*((_QWORD *)v2 + 4) + 856i64);
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  if ( !v4 )
    v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&this[-1].pAS3RawPtr->vfptr;
  if ( (unsigned __int8)v4 & 1 )
    v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v4 - 1);
  if ( v4
    && (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
          v4,
          (Scaleform::GFx::ASString *)(*((_QWORD *)v2 + 4) + 856i64),
          0)
     || Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(v4, v3, 1)) )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(v4, &result, v3, 1, 0);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4);
    v5 = (Scaleform::GFx::DisplayObject *)v1[-1].pClassName;
    v6 = result.pObject;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(v4, v6, v5);
    v7 = result.pObject;
    if ( result.pObject )
    {
      if ( (_QWORD)result.pObject & 1 )
      {
        --result.pObject;
      }
      else
      {
        v8 = result.pObject->RefCount;
        if ( v8 & 0x3FFFFF )
        {
          result.pObject->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
        }
      }
    }
  }
}

// File Line: 255
// RVA: 0x805560
void __fastcall Scaleform::GFx::AS3::AvmTextField::OnScroll(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::AS3::AvmTextField *v1; // rdi
  Scaleform::GFx::ASString *v2; // r14
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v3; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v4; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v5; // rsi
  signed __int64 v6; // rax
  signed __int64 v7; // rax
  signed __int64 v8; // rax
  Scaleform::GFx::DisplayObject *v9; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v10; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> result; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = (Scaleform::GFx::ASString *)*((_QWORD *)this[-1].pClassName + 4);
  v3 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  if ( !v3 )
    v3 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&this[-1].pAS3RawPtr->vfptr;
  if ( (unsigned __int8)v3 & 1 )
    v3 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v3 - 1);
  if ( v3 )
  {
    v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v3->pImpl.pObject;
    if ( v4 )
    {
      v5 = v4[1].pTable;
      if ( v5 )
      {
        v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               v4 + 1,
               v2 + 108,
               v2[108].pNode->HashFlags & v5->SizeMask);
        if ( v6 >= 0 )
        {
          v7 = (signed __int64)v5 + 8 * (3 * v6 + 3);
          if ( v7 )
          {
            v8 = v7 + 8;
            if ( v8 )
            {
              if ( *(_QWORD *)v8 )
              {
                if ( *(_QWORD *)(*(_QWORD *)v8 + 8i64) )
                {
                  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
                    v3,
                    &result,
                    v2 + 108,
                    1,
                    0);
                  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
                    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3);
                  v9 = (Scaleform::GFx::DisplayObject *)v1[-1].pClassName;
                  v10 = result.pObject;
                  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
                    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3);
                  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(v3, v10, v9);
                  v11 = result.pObject;
                  if ( result.pObject )
                  {
                    if ( (_QWORD)result.pObject & 1 )
                    {
                      --result.pObject;
                    }
                    else
                    {
                      v12 = result.pObject->RefCount;
                      if ( v12 & 0x3FFFFF )
                      {
                        result.pObject->RefCount = v12 - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
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
char __fastcall Scaleform::GFx::AS3::AvmTextField::OnEditorInsertingText(Scaleform::GFx::AS3::AvmTextField *this, unsigned __int64 pos, unsigned __int64 len, const wchar_t *wstr, unsigned int controllerIdx)
{
  const wchar_t *v5; // r15
  Scaleform::GFx::AS3::AvmTextField *v6; // rbp
  Scaleform::GFx::ASString *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v8; // rdi
  long double v9; // rcx
  Scaleform::GFx::AS3::ASVM *v10; // rsi
  Scaleform::GFx::AS3::Object **v11; // r8
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v12; // rbx
  Scaleform::GFx::DisplayObject *v13; // rsi
  char v14; // di
  unsigned int v16; // eax
  Scaleform::GFx::AS3::Value::VU v17; // [rsp+38h] [rbp-90h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-78h]
  int v19; // [rsp+70h] [rbp-58h]
  __int64 v20; // [rsp+78h] [rbp-50h]
  char v21; // [rsp+80h] [rbp-48h]
  int v22; // [rsp+90h] [rbp-38h]
  __int64 v23; // [rsp+98h] [rbp-30h]
  char v24; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+D0h] [rbp+8h]

  v5 = wstr;
  v6 = this;
  v7 = (Scaleform::GFx::ASString *)*((_QWORD *)this[-1].pClassName + 4);
  v8 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  if ( !v8 )
    v8 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&this[-1].pAS3RawPtr->vfptr;
  if ( (unsigned __int8)v8 & 1 )
    v8 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v8 - 1);
  if ( !v8
    || !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(v8, v7 + 106, 0)
    && !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(v8, v7 + 106, 1) )
  {
    return 1;
  }
  pobj.pObject = 0i64;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  v9 = *(double *)&v7[106].pNode;
  ptr.value.VNumber = v9;
  if ( *(_QWORD *)&v9 == *(_QWORD *)(*(_QWORD *)&v9 + 8i64) + 104i64 )
  {
    v17.VNumber = 0.0;
    ptr.value = v17;
    ptr.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v9 + 24i64);
  }
  v19 = 1;
  v20 = 0i64;
  v21 = 1;
  v22 = 1;
  v23 = 0i64;
  v24 = 1;
  v10 = *(Scaleform::GFx::AS3::ASVM **)(*((_QWORD *)v6[-1].pClassName + 4) + 80i64);
  v11 = (Scaleform::GFx::AS3::Object **)&v10->TextEventExClass;
  if ( !v10->ExtensionsEnabled )
    v11 = (Scaleform::GFx::AS3::Object **)&v10->TextEventClass;
  Scaleform::GFx::AS3::ASVM::_constructInstance(v10, &pobj, *v11, 3u, &ptr);
  v12 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)pobj.pObject;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pobj.pObject[1].16,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8);
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(v12, v5);
  if ( v10->ExtensionsEnabled )
    LODWORD(v12[1].vfptr) = controllerIdx;
  v13 = (Scaleform::GFx::DisplayObject *)v6[-1].pClassName;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v12->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
    v8,
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v12->vfptr,
    v13);
  v14 = ~(*((_BYTE *)&v12->0 + 84) >> 2) & 1;
  `eh vector destructor iterator'(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( (unsigned __int8)v12 & 1 )
  {
    pobj.pObject = (Scaleform::GFx::AS3::Object *)((char *)&v12[-1].Text.pNode + 7);
    return v14;
  }
  v16 = v12->RefCount;
  if ( !(v16 & 0x3FFFFF) )
    return v14;
  v12->RefCount = v16 - 1;
  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
  return v14;
}

// File Line: 306
// RVA: 0x807F50
void __fastcall Scaleform::GFx::AS3::AvmTextField::ProceedImageSubstitution(Scaleform::GFx::AS3::AvmTextField *this, Scaleform::GFx::AS3::VM *vm, int idx, Scaleform::GFx::AS3::Value *ve)
{
  Scaleform::GFx::AS3::VM *v4; // r13
  long double v5; // r12
  Scaleform::RefCountNTSImpl *v6; // rdi
  long double *v7; // rax
  unsigned int v8; // esi
  long double v9; // rbx
  Scaleform::GFx::AS3::Value::V2U v10; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v11; // rdx
  int v12; // er14
  __int64 v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned __int64 v19; // rbx
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  float v24; // xmm8_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm12_4
  float v28; // xmm11_4
  Scaleform::GFx::ASStringNode *v29; // rbx
  long double *v30; // rax
  unsigned int v31; // er14
  long double v32; // rsi
  Scaleform::GFx::AS3::Value::V2U v33; // rdx
  long double v34; // rcx
  int v35; // er15
  __int64 v36; // rax
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::ImageResource *v41; // r14
  Scaleform::GFx::AS2::AvmCharacter *v42; // r15
  Scaleform::GFx::Resource *v43; // rax
  Scaleform::GFx::Resource *v44; // rsi
  bool v45; // r15
  Scaleform::MemoryHeap *v46; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *v47; // rax
  Scaleform::GFx::ASString *v48; // rax
  Scaleform::GFx::ASStringNode *v49; // rcx
  long double *v50; // rax
  unsigned int v51; // er8
  long double v52; // rsi
  Scaleform::GFx::AS3::Value::V2U v53; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v54; // rcx
  int v55; // ecx
  __int64 v56; // rax
  Scaleform::GFx::ASString *v57; // rax
  Scaleform::GFx::ASStringNode *v58; // rcx
  Scaleform::GFx::ASStringNode *v59; // rcx
  Scaleform::GFx::ASStringNode *v60; // rcx
  long double v61; // r14
  Scaleform::GFx::ASString *v62; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v63; // rcx
  long double v64; // rsi
  __int64 v65; // rax
  Scaleform::GFx::ASStringNode *v66; // rcx
  Scaleform::GFx::ASString *v67; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v68; // rcx
  long double v69; // rsi
  __int64 v70; // rax
  Scaleform::GFx::ASStringNode *v71; // rcx
  Scaleform::GFx::ASString *v72; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v73; // rcx
  long double v74; // rsi
  __int64 v75; // rax
  Scaleform::GFx::ASStringNode *v76; // rcx
  float v77; // xmm6_4
  Scaleform::GFx::ASString *v78; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v79; // rcx
  long double v80; // rsi
  __int64 v81; // rax
  Scaleform::GFx::ASStringNode *v82; // rcx
  char *v83; // rsi
  Scaleform::GFx::TextField *v84; // r14
  Scaleform::GFx::ASStringNode *v85; // rax
  Scaleform::RefCountNTSImpl *v86; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v87; // rcx
  Scaleform::RefCountNTSImpl *v88; // rax
  int v89; // xmm2_4
  Scaleform::GFx::ASString *v90; // rax
  Scaleform::GFx::ASStringNode *v91; // rcx
  Scaleform::GFx::ASString *v92; // rax
  Scaleform::GFx::ASString v93; // [rsp+20h] [rbp-A8h]
  long double v94; // [rsp+28h] [rbp-A0h]
  Scaleform::GFx::AS3::Value p; // [rsp+30h] [rbp-98h]
  Scaleform::MemAddressStub *adr; // [rsp+50h] [rbp-78h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp-70h]
  __int64 v98; // [rsp+60h] [rbp-68h]
  Scaleform::GFx::AS3::Value v; // [rsp+68h] [rbp-60h]
  __int64 v100; // [rsp+88h] [rbp-40h]
  long double v101; // [rsp+90h] [rbp-38h]
  Scaleform::GFx::AS3::Value::V2U v102; // [rsp+98h] [rbp-30h]
  Scaleform::GFx::AS3::Multiname v103; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::AS3::Multiname v104; // [rsp+D0h] [rbp+8h]
  wchar_t pbuff; // [rsp+100h] [rbp+38h]
  Scaleform::RefCountNTSImpl *v106; // [rsp+128h] [rbp+60h]
  char v107; // [rsp+130h] [rbp+68h]
  Scaleform::GFx::AS3::Multiname v108; // [rsp+138h] [rbp+70h]
  Scaleform::GFx::AS3::Multiname v109; // [rsp+168h] [rbp+A0h]
  Scaleform::GFx::AS3::Multiname v110; // [rsp+198h] [rbp+D0h]
  Scaleform::MemAddressStub *v111; // [rsp+1C8h] [rbp+100h]
  Scaleform::GFx::AS3::Value::V2U v112; // [rsp+1D0h] [rbp+108h]
  Scaleform::GFx::AS3::Multiname v113; // [rsp+1D8h] [rbp+110h]
  char *v114; // [rsp+208h] [rbp+140h]
  Scaleform::Render::Text::DocView::ImageSubstitutor *v115; // [rsp+210h] [rbp+148h]
  __int64 v116; // [rsp+218h] [rbp+150h]
  Scaleform::StringBuffer v117; // [rsp+220h] [rbp+158h]
  Scaleform::GFx::AS2::AvmCharacter *v118; // [rsp+2F8h] [rbp+230h]
  unsigned int v119; // [rsp+308h] [rbp+240h]
  Scaleform::GFx::ASString v120; // [rsp+310h] [rbp+248h]

  v116 = -2i64;
  v4 = vm;
  if ( (ve->Flags & 0x1F) - 12 > 3 )
    return;
  adr = (Scaleform::MemAddressStub *)this->pDispObj;
  v111 = adr;
  v5 = ve->value.VNumber;
  v94 = ve->value.VNumber;
  v6 = 0i64;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0i64;
  v115 = Scaleform::GFx::TextField::CreateImageSubstitutor((Scaleform::GFx::TextField *)adr);
  if ( !v115 )
    goto LABEL_213;
  v106 = 0i64;
  v7 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
                        &result,
                        "subString");
  v8 = 10;
  p.Flags = 10;
  p.Bonus.pWeakProxy = 0i64;
  v9 = *v7;
  p.value.VNumber = v9;
  if ( *(_QWORD *)&v9 == *(_QWORD *)(*(_QWORD *)&v9 + 8i64) + 104i64 )
  {
    v9 = 0.0;
    p.value.VNumber = 0.0;
    v10.VObj = v112.VObj;
    p.value.VS._2 = v112;
    v8 = 12;
    p.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v9 + 24i64);
    v10.VObj = (Scaleform::GFx::AS3::Object *)p.value.VS._2;
  }
  v11 = (Scaleform::GFx::AS3::GASRefCountBase *)&v4->PublicNamespace.pObject->vfptr;
  v103.Kind = 0;
  v103.Obj.pObject = v11;
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
  v103.Name.Flags = 0;
  v103.Name.Bonus.pWeakProxy = 0i64;
  v12 = v8 & 0x1F;
  if ( (unsigned int)(v12 - 12) <= 3
    && v9 != 0.0
    && (v13 = *(_QWORD *)(*(_QWORD *)&v9 + 40i64), *(_DWORD *)(v13 + 120) == 17)
    && ~(*(_BYTE *)(v13 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v103.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v9 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v103.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v9 + 64i64));
    v103.Kind &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rsp+320h+p.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&v103.Name.Flags = *(_QWORD *)&p.Flags;
    v103.Name.Bonus.pWeakProxy = 0i64;
    v103.Name.value.VNumber = v9;
    v103.Name.value.VS._2 = v10;
    if ( v12 > 9 )
    {
      if ( (v8 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v12 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v9 + 24i64);
      }
      else if ( v12 > 10 )
      {
        if ( v12 <= 15 )
        {
          if ( v9 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v9 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v9 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v12 <= 17 && v10.VObj )
        {
          v10.VObj->RefCount = (v10.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (v103.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v103.Name, &v120);
      if ( v120.pNode->Size )
      {
        if ( *v120.pNode->pData == 64 )
        {
          v103.Kind |= 8u;
          v14 = Scaleform::GFx::ASString::Substring(&v120, &v93, 1, v120.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v103.Name, v14);
          v15 = v93.pNode;
          v16 = v93.pNode->RefCount == 1;
          --v15->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      v17 = v120.pNode;
      v16 = v120.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  if ( v12 > 9 )
  {
    if ( (v8 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      p.Bonus.pWeakProxy = 0i64;
      p.value = 0ui64;
      p.Flags = v8 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&p);
    }
  }
  v18 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( !*(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v5 + 32i64))(
                    COERCE_LONG_DOUBLE(*(_QWORD *)&v5),
                    &v120,
                    &v103,
                    &v) )
  {
    v92 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(v118, &v120);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&adr[24],
      "%s.setImageSubstitutions() failed for #%d element - subString should be specified",
      v92->pNode->pData,
      v119);
    v22 = v120.pNode;
LABEL_209:
    v16 = v22->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
LABEL_211:
    Scaleform::GFx::AS3::Multiname::~Multiname(&v103);
    if ( v106 )
      Scaleform::RefCountNTSImpl::Release(v106);
LABEL_213:
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        v16 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v16 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v.Bonus.pWeakProxy = 0i64;
        v.value.VNumber = 0.0;
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
  Scaleform::GFx::AS3::Value::ToStringValue(&v, (Scaleform::GFx::AS3::CheckResult *)&v120, v4->StringManagerRef);
  v93.pNode = v.value.VS._1.VStr;
  ++v93.pNode->RefCount;
  v19 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v93.pNode);
  if ( v19 > 0xF )
  {
    v20 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(v118, &v120);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&adr[24],
      "%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters",
      v20->pNode->pData,
      v119,
      v93.pNode);
    v21 = v120.pNode;
    v16 = v120.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    v22 = v93.pNode;
    goto LABEL_209;
  }
  Scaleform::UTF8Util::DecodeStringSafe(&pbuff, 0x14ui64, v93.pNode->pData, v93.pNode->Size + 1);
  v107 = v19;
  v23 = v93.pNode;
  v16 = v93.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  v24 = 0.0;
  v25 = 0.0;
  v26 = 0.0;
  v27 = 0.0;
  v28 = 0.0;
  v114 = 0i64;
  v29 = 0i64;
  v93.pNode = 0i64;
  v30 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
                         (Scaleform::GFx::ASString *)&v,
                         "image");
  v31 = 10;
  p.Flags = 10;
  p.Bonus.pWeakProxy = 0i64;
  v32 = *v30;
  p.value.VNumber = v32;
  if ( *(_QWORD *)&v32 == *(_QWORD *)(*(_QWORD *)&v32 + 8i64) + 104i64 )
  {
    v32 = 0.0;
    p.value.VNumber = 0.0;
    v33.VObj = v112.VObj;
    p.value.VS._2 = v112;
    v31 = 12;
    p.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v32 + 24i64);
    v33.VObj = (Scaleform::GFx::AS3::Object *)p.value.VS._2;
  }
  v34 = *(double *)&v4->PublicNamespace.pObject;
  LODWORD(v.Bonus.pWeakProxy) = 0;
  v.value.VNumber = v34;
  if ( v34 != 0.0 )
    *(_DWORD *)(*(_QWORD *)&v34 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v34 + 32i64) + 1) & 0x8FBFFFFF;
  LODWORD(v.value.VS._2.VObj) = 0;
  v100 = 0i64;
  v35 = v31 & 0x1F;
  if ( (unsigned int)(v35 - 12) <= 3
    && v32 != 0.0
    && (v36 = *(_QWORD *)(*(_QWORD *)&v32 + 40i64), *(_DWORD *)(v36 + 120) == 17)
    && ~(*(_BYTE *)(v36 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(
      (Scaleform::GFx::AS3::Value *)((char *)&v + 24),
      (Scaleform::GFx::ASString *)(*(_QWORD *)&v32 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v.value,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v32 + 64i64));
    LODWORD(v.Bonus.pWeakProxy) &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rsp+320h+p.Flags]; Prefetch to all cache levels }
    v.value.VS._2.VObj = *(Scaleform::GFx::AS3::Object **)&p.Flags;
    v100 = 0i64;
    v101 = v32;
    v102.VObj = v33.VObj;
    if ( v35 > 9 )
    {
      if ( (v31 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v35 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v32 + 24i64);
      }
      else if ( v35 > 10 )
      {
        if ( v35 <= 15 )
        {
          if ( v32 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v32 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v32 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v35 <= 17 && v33.VObj )
        {
          v33.VObj->RefCount = (v33.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( ((_QWORD)v.value.VS._2.VObj & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(
        (Scaleform::GFx::AS3::Value *)((char *)&v + 24),
        &v120);
      if ( v120.pNode->Size )
      {
        if ( *v120.pNode->pData == 64 )
        {
          LODWORD(v.Bonus.pWeakProxy) |= 8u;
          v37 = Scaleform::GFx::ASString::Substring(&v120, &result, 1, v120.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)((char *)&v + 24), v37);
          v38 = result.pNode;
          v16 = result.pNode->RefCount == 1;
          --v38->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v38);
        }
      }
      v39 = v120.pNode;
      v16 = v120.pNode->RefCount == 1;
      --v39->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v39);
    }
  }
  if ( v35 > 9 )
  {
    if ( (v31 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      p.Bonus.pWeakProxy = 0i64;
      p.value = 0ui64;
      p.Flags = v31 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&p);
    }
  }
  v40 = *(Scaleform::GFx::ASStringNode **)&v.Flags;
  v16 = *(_DWORD *)(*(_QWORD *)&v.Flags + 24i64) == 1;
  --v40->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  if ( !*(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Value::Extra *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::ASStringNode *))(**(_QWORD **)&v5 + 32i64))(
                    COERCE_LONG_DOUBLE(*(_QWORD *)&v5),
                    &v120,
                    &v.Bonus,
                    &v,
                    v93.pNode)
    || !(unsigned __int8)Scaleform::GFx::AS3::VM::IsOfType(
                           v4,
                           &v,
                           "flash.display.BitmapData",
                           v4->CurrentDomain.pObject) )
  {
    goto LABEL_204;
  }
  v41 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource((Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v.value.VS._1.VStr);
  v42 = v118;
  v43 = (Scaleform::GFx::Resource *)((__int64 (*)(void))v118->pDispObj->vfptr[66].__vecDelDtor)();
  v44 = v43;
  if ( v43 )
    Scaleform::Render::RenderBuffer::AddRef(v43);
  *(_QWORD *)&v.Flags = v44;
  if ( ((unsigned int (*)(void))v41->pImage->vfptr[3].__vecDelDtor)() )
  {
    v29 = (Scaleform::GFx::ASStringNode *)v41->pImage;
    if ( v29 )
      (*((void (__fastcall **)(Scaleform::Render::ImageBase *))v29->pData + 1))(v41->pImage);
    v93.pNode = v29;
  }
  else
  {
    v45 = Scaleform::GFx::StateBag::GetImageCreator(
            (Scaleform::GFx::StateBag *)&v44[1],
            (Scaleform::Ptr<Scaleform::GFx::ImageCreator> *)&v120)->pObject == 0i64;
    if ( v120.pNode )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v120.pNode);
    if ( v45 )
    {
      LODWORD(v120.pNode) = 135168;
      Scaleform::LogDebugMessage((Scaleform::LogMessageId)&v120, "ImageCreator is null in ProceedImageSubstitution");
      goto LABEL_105;
    }
    v42 = v118;
    v46 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v118);
    p.Flags = 3;
    p.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v46;
    p.value = (Scaleform::GFx::AS3::Value::VU)0x100000001ui64;
    adr = 0i64;
    result.pNode = 0i64;
    v98 = 0i64;
    v47 = Scaleform::GFx::StateBag::GetImageCreator(
            (Scaleform::GFx::StateBag *)&v44[1],
            (Scaleform::Ptr<Scaleform::GFx::ImageCreator> *)&v120);
    v29 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, Scaleform::GFx::AS3::Value *, Scaleform::Render::ImageBase *))v47->pObject->vfptr[4].__vecDelDtor)(
                                            v47->pObject,
                                            &p,
                                            v41->pImage);
    v93.pNode = v29;
    if ( v120.pNode )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v120.pNode);
  }
  if ( v29 )
  {
    (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::ASString *))v29->pData + 6))(v29, &result);
    v27 = (float)(v98 - LODWORD(result.pNode));
    v28 = (float)(HIDWORD(v98) - HIDWORD(result.pNode));
    v25 = v27 * 20.0;
    v26 = v28 * 20.0;
    if ( v27 == 0.0 || v28 == 0.0 )
    {
      v48 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(v42, &v120);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&adr[24],
        "%s.setImageSubstitutions() failed for #%d element - image has one zero dimension",
        v48->pNode->pData,
        v119,
        v93.pNode);
      v49 = v120.pNode;
      v16 = v120.pNode->RefCount == 1;
      --v49->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v49);
      if ( v44 )
        Scaleform::GFx::Resource::Release(v44);
LABEL_206:
      Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&v.Bonus);
      if ( v29 )
        (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))v29->pData + 2))(v29);
      goto LABEL_211;
    }
  }
LABEL_105:
  if ( v44 )
    Scaleform::GFx::Resource::Release(v44);
  if ( !v29 )
  {
LABEL_204:
    v90 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(v118, &v120);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&adr[24],
      "%s.setImageSubstitutions() failed for #%d element - 'image' is not specified or not a BitmapData",
      v90->pNode->pData,
      v119,
      v93.pNode);
    v91 = v120.pNode;
    v16 = v120.pNode->RefCount == 1;
    --v91->RefCount;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v91);
    goto LABEL_206;
  }
  v50 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
                         &result,
                         "width");
  v51 = 10;
  p.Flags = 10;
  p.Bonus.pWeakProxy = 0i64;
  v52 = *v50;
  p.value.VNumber = v52;
  if ( *(_QWORD *)&v52 == *(_QWORD *)(*(_QWORD *)&v52 + 8i64) + 104i64 )
  {
    v52 = 0.0;
    p.value.VNumber = 0.0;
    v53.VObj = v112.VObj;
    p.value.VS._2 = v112;
    v51 = 12;
    p.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v52 + 24i64);
    v53.VObj = (Scaleform::GFx::AS3::Object *)p.value.VS._2;
  }
  v54 = (Scaleform::GFx::AS3::GASRefCountBase *)&v4->PublicNamespace.pObject->vfptr;
  v104.Kind = 0;
  v104.Obj.pObject = v54;
  if ( v54 )
    v54->RefCount = (v54->RefCount + 1) & 0x8FBFFFFF;
  v104.Name.Flags = 0;
  v104.Name.Bonus.pWeakProxy = 0i64;
  v55 = v51 & 0x1F;
  if ( (unsigned int)(v55 - 12) <= 3
    && v52 != 0.0
    && (v56 = *(_QWORD *)(*(_QWORD *)&v52 + 40i64), *(_DWORD *)(v56 + 120) == 17)
    && ~(*(_BYTE *)(v56 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v104.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v52 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v104.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v52 + 64i64));
    v104.Kind &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rsp+320h+p.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&v104.Name.Flags = *(_QWORD *)&p.Flags;
    v104.Name.Bonus.pWeakProxy = 0i64;
    v104.Name.value.VNumber = v52;
    v104.Name.value.VS._2 = v53;
    if ( v55 > 9 )
    {
      if ( (v51 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v55 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v52 + 24i64);
      }
      else if ( v55 > 10 )
      {
        if ( v55 <= 15 )
        {
          if ( v52 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v52 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v52 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v55 <= 17 && v53.VObj )
        {
          v53.VObj->RefCount = (v53.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (v104.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v104.Name, &v120);
      if ( v120.pNode->Size )
      {
        if ( *v120.pNode->pData == 64 )
        {
          v104.Kind |= 8u;
          v57 = Scaleform::GFx::ASString::Substring(&v120, (Scaleform::GFx::ASString *)&v, 1, v120.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v104.Name, v57);
          v58 = *(Scaleform::GFx::ASStringNode **)&v.Flags;
          v16 = *(_DWORD *)(*(_QWORD *)&v.Flags + 24i64) == 1;
          --v58->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v58);
        }
      }
      v59 = v120.pNode;
      v16 = v120.pNode->RefCount == 1;
      --v59->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v59);
    }
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v60 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v60->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v60);
  v61 = v94;
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(_QWORD, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v94 + 32i64))(
                   *(_QWORD *)&v94,
                   &v120,
                   &v104,
                   &v) )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(&v, (Scaleform::GFx::AS3::CheckResult *)&v120, &v94);
    v25 = v94 * 20.0;
  }
  v62 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          &v120,
          "height");
  Scaleform::GFx::AS3::Value::Value(&p, v62);
  v63 = (Scaleform::GFx::AS3::GASRefCountBase *)&v4->PublicNamespace.pObject->vfptr;
  v113.Kind = 0;
  v113.Obj.pObject = v63;
  if ( v63 )
    v63->RefCount = (v63->RefCount + 1) & 0x8FBFFFFF;
  v113.Name.Flags = 0;
  v113.Name.Bonus.pWeakProxy = 0i64;
  if ( (p.Flags & 0x1F) - 12 <= 3
    && (v64 = p.value.VNumber, *(_QWORD *)&p.value.VNumber)
    && (v65 = *(_QWORD *)(*(_QWORD *)&p.value.VNumber + 40i64), *(_DWORD *)(v65 + 120) == 17)
    && ~(*(_BYTE *)(v65 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v113.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&p.value.VNumber + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v113.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v64 + 64i64));
    v113.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v113.Name, &p);
    Scaleform::GFx::AS3::Multiname::PostProcessName(&v113, 0);
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v66 = v120.pNode;
  v16 = v120.pNode->RefCount == 1;
  --v66->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v66);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v61 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v61),
                   &v120,
                   &v113,
                   &v) )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(&v, (Scaleform::GFx::AS3::CheckResult *)&v120, &v94);
    v26 = v94 * 20.0;
  }
  v67 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          &v120,
          "baseLineX");
  Scaleform::GFx::AS3::Value::Value(&p, v67);
  v68 = (Scaleform::GFx::AS3::GASRefCountBase *)&v4->PublicNamespace.pObject->vfptr;
  v110.Kind = 0;
  v110.Obj.pObject = v68;
  if ( v68 )
    v68->RefCount = (v68->RefCount + 1) & 0x8FBFFFFF;
  v110.Name.Flags = 0;
  v110.Name.Bonus.pWeakProxy = 0i64;
  if ( (p.Flags & 0x1F) - 12 <= 3
    && (v69 = p.value.VNumber, *(_QWORD *)&p.value.VNumber)
    && (v70 = *(_QWORD *)(*(_QWORD *)&p.value.VNumber + 40i64), *(_DWORD *)(v70 + 120) == 17)
    && ~(*(_BYTE *)(v70 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v110.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&p.value.VNumber + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v110.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v69 + 64i64));
    v110.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v110.Name, &p);
    Scaleform::GFx::AS3::Multiname::PostProcessName(&v110, 0);
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v71 = v120.pNode;
  v16 = v120.pNode->RefCount == 1;
  --v71->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v71);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v61 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v61),
                   &v120,
                   &v110,
                   &v) )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(&v, (Scaleform::GFx::AS3::CheckResult *)&v120, &v94);
    v24 = v94 * 20.0;
  }
  v72 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          &v120,
          "baseLineY");
  Scaleform::GFx::AS3::Value::Value(&p, v72);
  v73 = (Scaleform::GFx::AS3::GASRefCountBase *)&v4->PublicNamespace.pObject->vfptr;
  v109.Kind = 0;
  v109.Obj.pObject = v73;
  if ( v73 )
    v73->RefCount = (v73->RefCount + 1) & 0x8FBFFFFF;
  v109.Name.Flags = 0;
  v109.Name.Bonus.pWeakProxy = 0i64;
  if ( (p.Flags & 0x1F) - 12 <= 3
    && (v74 = p.value.VNumber, *(_QWORD *)&p.value.VNumber)
    && (v75 = *(_QWORD *)(*(_QWORD *)&p.value.VNumber + 40i64), *(_DWORD *)(v75 + 120) == 17)
    && ~(*(_BYTE *)(v75 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v109.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&p.value.VNumber + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v109.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v74 + 64i64));
    v109.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v109.Name, &p);
    Scaleform::GFx::AS3::Multiname::PostProcessName(&v109, 0);
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v76 = v120.pNode;
  v16 = v120.pNode->RefCount == 1;
  --v76->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v76);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v61 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v61),
                   &v120,
                   &v109,
                   &v) )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(&v, (Scaleform::GFx::AS3::CheckResult *)&v120, &v94);
    v77 = v94 * 20.0;
  }
  else
  {
    v77 = v28 - 20.0;
  }
  v78 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          &v120,
          "id");
  Scaleform::GFx::AS3::Value::Value(&p, v78);
  v79 = (Scaleform::GFx::AS3::GASRefCountBase *)&v4->PublicNamespace.pObject->vfptr;
  v108.Kind = 0;
  v108.Obj.pObject = v79;
  if ( v79 )
    v79->RefCount = (v79->RefCount + 1) & 0x8FBFFFFF;
  v108.Name.Flags = 0;
  v108.Name.Bonus.pWeakProxy = 0i64;
  if ( (p.Flags & 0x1F) - 12 <= 3
    && (v80 = p.value.VNumber, *(_QWORD *)&p.value.VNumber)
    && (v81 = *(_QWORD *)(*(_QWORD *)&p.value.VNumber + 40i64), *(_DWORD *)(v81 + 120) == 17)
    && ~(*(_BYTE *)(v81 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v108.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&p.value.VNumber + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v108.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v80 + 64i64));
    v108.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v108.Name, &p);
    Scaleform::GFx::AS3::Multiname::PostProcessName(&v108, 0);
  }
  Scaleform::GFx::AS3::Value::~Value(&p);
  v82 = v120.pNode;
  v16 = v120.pNode->RefCount == 1;
  --v82->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v82);
  Scaleform::StringBuffer::StringBuffer(&v117, Scaleform::Memory::pGlobalHeap);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v61 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v61),
                   &v120,
                   &v108,
                   &v) )
  {
    Scaleform::GFx::AS3::Value::Convert2String(&v, (Scaleform::GFx::AS3::CheckResult *)&v120, &v117);
    v83 = &customWorldMapCaption;
    if ( v117.pData )
      v83 = v117.pData;
  }
  else
  {
    v83 = v114;
  }
  v84 = (Scaleform::GFx::TextField *)adr;
  v85 = (Scaleform::GFx::ASStringNode *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::operator new(
                                          0x50ui64,
                                          adr);
  v120.pNode = v85;
  if ( v85 )
  {
    Scaleform::Render::Text::ImageDesc::ImageDesc((Scaleform::Render::Text::ImageDesc *)v85);
    v6 = v86;
  }
  if ( v106 )
    Scaleform::RefCountNTSImpl::Release(v106);
  v106 = v6;
  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))v29->pData + 1))(v29);
  v87 = v6[1].vfptr;
  if ( v87 )
    (*((void (**)(void))v87->__vecDelDtor + 2))();
  v6[1].vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)v29;
  *(float *)&v106[1].RefCount = v24 * 0.050000001;
  *((float *)&v106[1].RefCount + 1) = v77 * 0.050000001;
  *(float *)&v106[2].vfptr = v25;
  *((float *)&v106[2].vfptr + 1) = v26;
  if ( v83 )
    Scaleform::GFx::TextField::AddIdImageDescAssoc(v84, v83, (Scaleform::Render::Text::ImageDesc *)v106);
  v88 = v106;
  v89 = *(&v106[1].RefCount + 1) ^ _xmm[0];
  *((float *)&v106[3].RefCount + 1) = COERCE_FLOAT(v106[1].RefCount ^ _xmm[0]) + *((float *)&v106[3].RefCount + 1);
  *((float *)&v88[4].RefCount + 1) = *(float *)&v89 + *((float *)&v88[4].RefCount + 1);
  Scaleform::Render::Matrix2x4<float>::AppendScaling(
    (Scaleform::Render::Matrix2x4<float> *)&v106[3],
    *(float *)&v106[2].vfptr / v27,
    *((float *)&v106[2].vfptr + 1) / v28);
  Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(
    v115,
    (Scaleform::Render::Text::DocView::ImageSubstitutor::Element *)&pbuff);
  v84->pDocument.pObject->RTFlags |= 2u;
  Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v118->pDispObj);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v117);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v108);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v109);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v110);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v113);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v104);
  Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&v.Bonus);
  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))v29->pData + 2))(v29);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v103);
  if ( v106 )
    Scaleform::RefCountNTSImpl::Release(v106);
  Scaleform::GFx::AS3::Value::~Value(&v);
}pl::Release(v106);
  Scaleform::GFx::AS3::Value::~Value(&v);
}

