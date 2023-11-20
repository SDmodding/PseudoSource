// File Line: 15
// RVA: 0x146A7F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::ValueTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::ValueTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::sInventory.vfptr,
    "UITest::ValueTest",
    v0);
  UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::ValueTest>::`vftable;
  UFG::qReflectInventory<UITest::ValueTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::ValueTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 16
// RVA: 0x146A770
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::ValueSubClass_UITest::ValueTest_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::ValueSubClass", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::sInventory.vfptr,
    "UITest::ValueSubClass",
    v0);
  UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::ValueSubClass>::`vftable;
  UFG::qReflectInventory<UITest::ValueSubClass>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::ValueSubClass_UITest::ValueTest_::sInventory__);
}

// File Line: 17
// RVA: 0x146A570
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::PointerTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::PointerTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::sInventory.vfptr,
    "UITest::PointerTest",
    v0);
  UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::PointerTest>::`vftable;
  UFG::qReflectInventory<UITest::PointerTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::PointerTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 18
// RVA: 0x146A020
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::StringTest_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UITest::StringTest,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 19
// RVA: 0x146A370
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::EnumValueTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::EnumValueTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::sInventory.vfptr,
    "UITest::EnumValueTest",
    v0);
  UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::EnumValueTest>::`vftable;
  UFG::qReflectInventory<UITest::EnumValueTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::EnumValueTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 20
// RVA: 0x1469B50
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::ArrayTest_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UITest::ArrayTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UITest::ArrayTest,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UITest::ArrayTest>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 21
// RVA: 0x146A070
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::ArrayPointerTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::ArrayPointerTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::sInventory.vfptr,
    "UITest::ArrayPointerTest",
    v0);
  UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::ArrayPointerTest>::`vftable;
  UFG::qReflectInventory<UITest::ArrayPointerTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::ArrayPointerTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 22
// RVA: 0x1469D10
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::HandleTest_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UITest::HandleTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UITest::HandleTest,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UITest::HandleTest>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 23
// RVA: 0x1469FE0
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::HandleArrayTest_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UITest::HandleArrayTest,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 24
// RVA: 0x146A670
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::SymbolTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::SymbolTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::sInventory.vfptr,
    "UITest::SymbolTest",
    v0);
  UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::SymbolTest>::`vftable;
  UFG::qReflectInventory<UITest::SymbolTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::SymbolTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 25
// RVA: 0x146A4F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::MathValueTest_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::MathValueTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::sInventory.vfptr,
    "UITest::MathValueTest",
    v0);
  UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::MathValueTest>::`vftable;
  UFG::qReflectInventory<UITest::MathValueTest>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::MathValueTest_UFG::qReflectObject_::sInventory__);
}

// File Line: 26
// RVA: 0x1469FC0
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::DefaultValues_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UITest::DefaultValues,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 27
// RVA: 0x1469B90
void dynamic_initializer_for__UFG::qReflectObjectType_UITest::ColourTest_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UITest::ColourTest", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UITest::ColourTest,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UITest::ColourTest>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 28
// RVA: 0x146A6F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UITest::UITestCase_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UITest::UITestCase", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::sInventory.vfptr,
    "UITest::UITestCase",
    v0);
  UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UITest::UITestCase>::`vftable;
  UFG::qReflectInventory<UITest::UITestCase>::OnAddToWarehouse(&UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UITest::UITestCase_UFG::qReflectObject_::sInventory__);
}

// File Line: 29
// RVA: 0x146A1F0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_DNA::DUIDNAInspector_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("DNA::DUIDNAInspector", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::sInventory.vfptr,
    "DNA::DUIDNAInspector",
    v0);
  UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<DNA::DUIDNAInspector>::`vftable;
  UFG::qReflectInventory<DNA::DUIDNAInspector>::OnAddToWarehouse(&UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_DNA::DUIDNAInspector_UFG::DUIWindow_::sInventory__);
}

// File Line: 30
// RVA: 0x1469F80
void dynamic_initializer_for__UFG::qReflectObjectType_DNA::DUIReflectInspector_UFG::DUIWindow_::sFactoryOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("DNA::DUIReflectInspector", 0xFFFFFFFFFFFFFFFFui64);
  UFG::FactoryOperation::FactoryOperation(
    &UFG::qReflectObjectType<DNA::DUIReflectInspector,UFG::DUIWindow>::sFactoryOp,
    v0,
    UFG::OnCreateClass<DNA::DUIReflectInspector>,
    (void (__fastcall *)(char *))UFG::OnDeleteClass<UFG::DUIThemeEditorWindow>);
}

// File Line: 49
// RVA: 0x1B0850
void __fastcall DNA::DUIDNAWidget::~DUIDNAWidget(DNA::DUIDNAWidget *this)
{
  DNA::DUIDNAWidget *v1; // rbx
  UFG::qReflectType **v2; // rcx
  DNA::DUIDNAWidget::ExpandState *v3; // rcx
  DNA::PropertyBagWrapper *v4; // rdi
  DNA::DUIDNAWidget::ExpandState *v5; // rcx
  UFG::qReflectType **v6; // rcx

  v1 = this;
  v2 = this->mTypeStack.p;
  if ( v2 )
    operator delete[](v2);
  v1->mTypeStack.p = 0i64;
  *(_QWORD *)&v1->mTypeStack.size = 0i64;
  v3 = v1->mExpandState.p;
  if ( v3 )
    operator delete[](v3);
  v1->mExpandState.p = 0i64;
  *(_QWORD *)&v1->mExpandState.size = 0i64;
  v4 = v1->mWrapper;
  if ( v4 )
  {
    DNA::PropertyBagWrapper::~PropertyBagWrapper(v1->mWrapper);
    operator delete[](v4);
  }
  UFG::qString::~qString(&v1->mEditValue);
  v5 = v1->mExpandState.p;
  if ( v5 )
    operator delete[](v5);
  v1->mExpandState.p = 0i64;
  *(_QWORD *)&v1->mExpandState.size = 0i64;
  v6 = v1->mTypeStack.p;
  if ( v6 )
    operator delete[](v6);
  v1->mTypeStack.p = 0i64;
  *(_QWORD *)&v1->mTypeStack.size = 0i64;
}

// File Line: 86
// RVA: 0x1B51B0
void __fastcall DNA::DUIDNAWidget::PopulateUIRecursive(DNA::DUIDNAWidget *this, DNA::PropertyBagWrapper *wrapper, UFG::qReflectField *parent_field)
{
  DNA::DUIDNAWidget *v3; // rbx
  char *v4; // r8
  UFG::qArray<UFG::qReflectType const *,0> *v5; // r9
  __int64 v6; // rsi
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // edx
  UFG::qReflectField *v10; // rsi
  UFG::ReflectionDB *v11; // rax
  UFG::qReflectType *v12; // rdi
  DNA::PropertyWrapper *v13; // rax
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned __int64 v16; // rdi
  DNA::PropertyWrapper *v17; // rax
  UFG::qString *v18; // rax
  unsigned int v19; // eax
  bool *v20; // rax
  UFG::qString *v21; // rax
  DNA::PropertyBagWrapper *v22; // rdi
  UFG::ReflectionDB *v23; // rax
  UFG::qReflectType *v24; // r8
  DNA::PropertyBagWrapper *v25; // rax
  int v26; // ecx
  unsigned int v27; // edi
  DNA::PropertyWrapper *v28; // rsi
  bool *v29; // rax
  UFG::qString *v30; // rcx
  bool *v31; // rax
  unsigned int v32; // edi
  unsigned __int64 v33; // rdi
  char *v34; // rdi
  bool *v35; // rax
  unsigned __int64 v36; // rdi
  __int64 lengthb[2]; // [rsp+20h] [rbp-E0h]
  unsigned int v38; // [rsp+30h] [rbp-D0h]
  DNA::PropertyBagWrapper *wrappera; // [rsp+38h] [rbp-C8h]
  UFG::qReflectType *type; // [rsp+40h] [rbp-C0h]
  DNA::PropertyInfo v41; // [rsp+48h] [rbp-B8h]
  unsigned __int64 v42; // [rsp+60h] [rbp-A0h]
  UFG::qReflectField *v43; // [rsp+68h] [rbp-98h]
  UFG::qArray<UFG::qReflectType const *,0> *v44; // [rsp+70h] [rbp-90h]
  UFG::qReflectField *v45; // [rsp+78h] [rbp-88h]
  UFG::qString result; // [rsp+80h] [rbp-80h]
  __int64 v47; // [rsp+A8h] [rbp-58h]
  UFG::qString v48; // [rsp+B0h] [rbp-50h]
  UFG::qString v49; // [rsp+D8h] [rbp-28h]
  UFG::qString v50; // [rsp+100h] [rbp+0h]
  UFG::qString v51; // [rsp+128h] [rbp+28h]
  UFG::qString v52; // [rsp+150h] [rbp+50h]
  UFG::qString v53; // [rsp+178h] [rbp+78h]
  UFG::qString v54; // [rsp+1A0h] [rbp+A0h]
  UFG::qString v55; // [rsp+1C8h] [rbp+C8h]
  DNA::PropertyBagWrapper *v; // [rsp+220h] [rbp+120h]
  DNA::PropertyBagWrapper *v57; // [rsp+228h] [rbp+128h]
  UFG::qReflectField *field; // [rsp+230h] [rbp+130h]
  DNA::PropertyWrapper *property_wrapper; // [rsp+238h] [rbp+138h]

  field = parent_field;
  v57 = wrapper;
  v47 = -2i64;
  v3 = this;
  v38 = 0;
  v4 = (char *)wrapper->mSchema->mReflectionType;
  v = (DNA::PropertyBagWrapper *)wrapper->mSchema->mReflectionType;
  v5 = &this->mTypeStack;
  v44 = &this->mTypeStack;
  v6 = this->mTypeStack.size;
  v7 = v6 + 1;
  v8 = this->mTypeStack.capacity;
  if ( (signed int)v6 + 1 > v8 )
  {
    if ( v8 )
      v9 = 2 * v8;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 <= 2 )
      v9 = 2;
    if ( v9 - v7 > 0x10000 )
      v9 = v6 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mTypeStack,
      v9,
      "qArray.Add");
    v4 = (char *)v;
    v5 = &v3->mTypeStack;
  }
  v5->size = v7;
  v5->p[v6] = (UFG::qReflectType *)v4;
  v10 = (UFG::qReflectField *)*((_QWORD *)v4 + 21);
  v43 = v10;
  v45 = (UFG::qReflectField *)(v4 + 160);
  if ( v10 != (UFG::qReflectField *)(v4 + 160) )
  {
    while ( 1 )
    {
      v11 = UFG::ReflectionDB::Instance();
      v12 = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v11, v10->mTypeName);
      DNA::DUIDNAWidget::GetDisplayName(v3, &result, v10);
      v13 = DNA::PropertyBagWrapper::GetProperty(v57, v10->mName);
      property_wrapper = v13;
      v14 = v10->mFlags;
      if ( !(v14 & 0x40) )
      {
        v15 = v12->mFlags;
        if ( v15 & 8 || (v15 & 0x80u) != 0 || v15 & 1 || v15 & 4 )
        {
          DNA::DUIDNAWidget::AddField(v3, v13, v10, v12);
        }
        else
        {
          if ( _bittest((const signed int *)&v14, 0xDu) )
          {
            if ( v15 & 0x10 )
            {
              v16 = 0i64;
              if ( v10->mArrayLength )
              {
                do
                {
                  v = 0i64;
                  v17 = DNA::PropertyBagWrapper::GetProperty(v57, v10->mName);
                  DNA::PropertyWrapper::Get(v17, v16, &v, 0);
                  if ( v )
                  {
                    DNA::DUIDNAWidget::GetDisplayName(v3, &v48, v10);
                    if ( v10->mArrayLength <= 1 )
                    {
                      v18 = UFG::qString::FormatEx(&v53, "%s", v48.mData);
                      v38 |= 2u;
                    }
                    else
                    {
                      v18 = UFG::qString::FormatEx(&v54, "%s[%d]", v48.mData, v16, lengthb[0]);
                      v38 |= 1u;
                    }
                    UFG::qString::qString(&v50, v18);
                    v19 = v38;
                    if ( v38 & 2 )
                    {
                      v38 &= 0xFFFFFFFD;
                      UFG::qString::~qString(&v53);
                      v19 = v38;
                    }
                    if ( v19 & 1 )
                    {
                      v38 = v19 & 0xFFFFFFFE;
                      UFG::qString::~qString(&v54);
                    }
                    v20 = DNA::DUIDNAWidget::GetExpandedState(v3, property_wrapper, v16);
                    if ( (unsigned __int8)UFG::DUIContext::Collapsible(v3->mContext, v50.mData, v20) )
                    {
                      UFG::DUIContext::BeginIndent(v3->mContext);
                      DNA::DUIDNAWidget::PopulateUIRecursive(v3, v, v10);
                      UFG::DUIContext::EndIndent(v3->mContext);
                    }
                    UFG::qString::~qString(&v50);
                    UFG::qString::~qString(&v48);
                  }
                  ++v16;
                }
                while ( v16 < v10->mArrayLength );
              }
            }
            goto LABEL_80;
          }
          if ( !(v14 & 0x20) )
          {
            if ( !(v14 & 1) )
            {
              if ( v14 & 2 )
              {
                v33 = 0i64;
                if ( v10->mArrayLength )
                {
                  do
                  {
                    v = 0i64;
                    DNA::PropertyWrapper::Get(v13, v33, &v, 0);
                    DNA::DUIDNAWidget::PopulateUIRecursive(v3, v, v10);
                    ++v33;
                    v13 = property_wrapper;
                  }
                  while ( v33 < v10->mArrayLength );
                }
              }
              else if ( !DNA::IsHidden(v3->mTypeStack.p[v3->mTypeStack.size - 1], v10) )
              {
                v34 = result.mData;
                v35 = DNA::DUIDNAWidget::GetExpandedState(v3, property_wrapper, 0);
                if ( (unsigned __int8)UFG::DUIContext::Collapsible(v3->mContext, v34, v35) )
                {
                  v36 = 0i64;
                  if ( v10->mArrayLength )
                  {
                    do
                    {
                      v = 0i64;
                      DNA::PropertyWrapper::Get(property_wrapper, v36, &v, 0);
                      if ( (unsigned __int8)DNA::HasEditor(v10, "ColourPicker") )
                      {
                        DNA::DUIDNAWidget::AddColourType(v3, v);
                      }
                      else
                      {
                        UFG::DUIContext::BeginIndent(v3->mContext);
                        DNA::DUIDNAWidget::PopulateUIRecursive(v3, v, v10);
                        UFG::DUIContext::EndIndent(v3->mContext);
                      }
                      ++v36;
                    }
                    while ( v36 < v10->mArrayLength );
                  }
                }
              }
            }
            goto LABEL_80;
          }
          v21 = DNA::DUIDNAWidget::GetDisplayName(v3, &v55, field);
          UFG::qString::Set(&result, v21->mData, v21->mLength, 0i64, 0);
          UFG::qString::~qString(&v55);
          v22 = (DNA::PropertyBagWrapper *)v12->mOrderedFields.mNode.mNext;
          v = v22;
          v42 = 0i64;
          if ( v10->mArrayLength )
          {
            do
            {
              DNA::PropertyWrapper::GetPropertyInfo(property_wrapper, &v41);
              v23 = UFG::ReflectionDB::Instance();
              v24 = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v23, (const char *)v22[1].mPropertyBags.p);
              type = v24;
              if ( !v41.Size )
                goto LABEL_62;
              v25 = v;
              v26 = (int)v[2].mPropertyBags.p;
              if ( v26 & 8 || (v26 & 0x80u) != 0 || v26 & 4 || v26 & 1 )
              {
                v32 = 0;
                if ( v41.Size )
                {
                  do
                  {
                    UFG::DUIContext::BeginIndent(v3->mContext);
                    UFG::DUIContext::BeginGridLayout(v3->mContext, 2, 1, 4);
                    UFG::DUIContext::BeginIndent(v3->mContext);
                    UFG::qString::FormatEx(&v49, "%s[%d]", result.mData, v32, lengthb[0]);
                    UFG::DUIContext::Label(v3->mContext, v49.mData);
                    UFG::DUIContext::EndIndent(v3->mContext);
                    LODWORD(lengthb[0]) = v32;
                    DNA::DUIDNAWidget::AddBasicType(v3, property_wrapper, v10, type);
                    UFG::DUIContext::EndLayoutHorizontal(v3->mContext);
                    UFG::DUIContext::EndIndent(v3->mContext);
                    UFG::qString::~qString(&v49);
                    ++v32;
                  }
                  while ( v32 < v41.Size );
                  v22 = v;
                  goto LABEL_62;
                }
              }
              else
              {
                v27 = 0;
                if ( v41.Size )
                {
                  v28 = property_wrapper;
                  while ( (_QWORD)v25[2].mPropertyBags.p & 0x4000 )
                  {
                    if ( v24->mFlags & 0x10 )
                    {
                      wrappera = 0i64;
                      DNA::PropertyWrapper::Get(v28, v27, &wrappera, 0);
                      if ( wrappera )
                      {
                        UFG::DUIContext::BeginIndent(v3->mContext);
                        UFG::qString::FormatEx(&v52, "%s[%d] [%s]", result.mData, v27, wrappera->mSchema->mName.mData);
                        v29 = DNA::DUIDNAWidget::GetExpandedState(v3, v28, v27);
                        if ( (unsigned __int8)UFG::DUIContext::Collapsible(v3->mContext, v52.mData, v29) )
                        {
                          UFG::DUIContext::BeginIndent(v3->mContext);
                          DNA::DUIDNAWidget::PopulateUIRecursive(v3, wrappera, (UFG::qReflectField *)v);
                          UFG::DUIContext::EndIndent(v3->mContext);
                        }
                        UFG::DUIContext::EndIndent(v3->mContext);
                        v30 = &v52;
                        goto LABEL_54;
                      }
                      goto LABEL_55;
                    }
LABEL_56:
                    if ( ++v27 >= v41.Size )
                    {
                      v10 = v43;
                      v22 = v;
                      goto LABEL_62;
                    }
                  }
                  wrappera = 0i64;
                  DNA::PropertyWrapper::Get(v28, v27, &wrappera, 0);
                  UFG::DUIContext::BeginIndent(v3->mContext);
                  UFG::qString::FormatEx(&v51, "%s[%d]", result.mData, v27, lengthb[0]);
                  v31 = DNA::DUIDNAWidget::GetExpandedState(v3, v28, v27);
                  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v3->mContext, v51.mData, v31) )
                  {
                    if ( (unsigned __int8)DNA::HasEditor(type, "ColourPicker") )
                    {
                      DNA::DUIDNAWidget::AddColourType(v3, wrappera);
                    }
                    else
                    {
                      UFG::DUIContext::BeginIndent(v3->mContext);
                      DNA::DUIDNAWidget::PopulateUIRecursive(v3, wrappera, (UFG::qReflectField *)v);
                      UFG::DUIContext::EndIndent(v3->mContext);
                    }
                  }
                  UFG::DUIContext::EndIndent(v3->mContext);
                  v30 = &v51;
LABEL_54:
                  UFG::qString::~qString(v30);
LABEL_55:
                  v25 = v;
                  v24 = type;
                  goto LABEL_56;
                }
              }
              v22 = v;
LABEL_62:
              if ( v41.States.p )
                operator delete[](v41.States.p);
              v41.States.p = 0i64;
              *(_QWORD *)&v41.States.size = 0i64;
              ++v42;
            }
            while ( v42 < v10->mArrayLength );
          }
        }
      }
LABEL_80:
      UFG::qString::~qString(&result);
      v10 = (UFG::qReflectField *)v10->mNext;
      v43 = v10;
      if ( v10 == v45 )
      {
        v5 = v44;
        break;
      }
    }
  }
  if ( v5->size > 1 )
    --v5->size;
  else
    v5->size = 0;
}

// File Line: 284
// RVA: 0x1B3D80
UFG::qString *__fastcall DNA::DUIDNAWidget::GetDisplayName(DNA::DUIDNAWidget *this, UFG::qString *result, UFG::qReflectField *field)
{
  UFG::qString *v3; // rbx

  v3 = result;
  DNA::GetDisplayName(result, this->mTypeStack.p[this->mTypeStack.size - 1], field);
  return v3;
}

// File Line: 304
// RVA: 0x1B3E20
bool *__fastcall DNA::DUIDNAWidget::GetExpandedState(DNA::DUIDNAWidget *this, DNA::PropertyWrapper *property_wrapper, unsigned int array_index)
{
  __int64 v3; // r14
  unsigned int v4; // ebp
  unsigned int v5; // er15
  DNA::PropertyWrapper *v6; // r12
  DNA::DUIDNAWidget *v7; // rdi
  unsigned int v8; // er9
  DNA::DUIDNAWidget::ExpandState *v9; // rax
  unsigned int v10; // ebx
  unsigned int v11; // esi
  unsigned int v12; // ebx
  bool *result; // rax
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // r13
  DNA::DUIDNAWidget::ExpandState *v16; // rcx
  __int64 v17; // rdx
  signed __int64 v18; // rcx

  v3 = this->mExpandState.size;
  v4 = 0;
  v5 = array_index;
  v6 = property_wrapper;
  v7 = this;
  v8 = 0;
  if ( (_DWORD)v3 )
  {
    v9 = this->mExpandState.p;
    while ( v9->mData != property_wrapper || v9->mArrayIndex != array_index )
    {
      ++v8;
      ++v9;
      if ( v8 >= (unsigned int)v3 )
        goto LABEL_6;
    }
    result = &v9->mExpanded;
  }
  else
  {
LABEL_6:
    v10 = this->mExpandState.capacity;
    v11 = v3 + 1;
    if ( (signed int)v3 + 1 > v10 )
    {
      if ( v10 )
        v12 = 2 * v10;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 - v11 > 0x10000 )
        v12 = v3 + 65537;
      if ( v12 != this->mExpandState.size )
      {
        v14 = 16i64 * v12;
        if ( !is_mul_ok(v12, 0x10ui64) )
          v14 = -1i64;
        v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
        if ( v7->mExpandState.p )
        {
          if ( v7->mExpandState.size > 0 )
          {
            do
            {
              v16 = v7->mExpandState.p;
              v17 = v4++;
              v17 *= 2i64;
              v15[v17] = *(UFG::allocator::free_link *)((char *)&v16->mData + 8 * v17);
              v15[v17 + 1] = *(UFG::allocator::free_link *)((char *)&v16->mArrayIndex + 8 * v17);
            }
            while ( v4 < v7->mExpandState.size );
          }
          operator delete[](v7->mExpandState.p);
        }
        v7->mExpandState.p = (DNA::DUIDNAWidget::ExpandState *)v15;
        v7->mExpandState.capacity = v12;
      }
    }
    v7->mExpandState.size = v11;
    v18 = (signed __int64)&v7->mExpandState.p[v3];
    *(_BYTE *)(v18 + 12) = 0;
    result = (bool *)(v18 + 12);
    *(_QWORD *)v18 = v6;
    *(_DWORD *)(v18 + 8) = v5;
  }
  return result;
}

// File Line: 322
// RVA: 0x1B2A10
void __fastcall DNA::DUIDNAWidget::AddField(DNA::DUIDNAWidget *this, DNA::PropertyWrapper *property_wrapper, UFG::qReflectField *field, UFG::qReflectType *field_type)
{
  UFG::qReflectField *v4; // r13
  DNA::PropertyWrapper *v5; // r15
  DNA::DUIDNAWidget *v6; // rsi
  int v7; // ebx
  signed int v8; // er14
  char *v9; // rdi
  bool *v10; // rax
  signed int i; // edi
  UFG::qString *v12; // rax
  DNA::PropertyInfo result; // [rsp+10h] [rbp-71h]
  char *name; // [rsp+28h] [rbp-59h]
  UFG::qString text; // [rsp+38h] [rbp-49h]
  __int64 v16; // [rsp+60h] [rbp-21h]
  UFG::qString v17; // [rsp+68h] [rbp-19h]
  UFG::qString v18; // [rsp+90h] [rbp+Fh]
  UFG::qReflectType *field_typea; // [rsp+100h] [rbp+7Fh]

  v16 = -2i64;
  v4 = field;
  v5 = property_wrapper;
  v6 = this;
  v7 = 0;
  if ( !DNA::IsHidden(this->mTypeStack.p[this->mTypeStack.size - 1], field) )
  {
    v8 = v5->mSchemaField->mArrayLength;
    if ( v8 < 0 )
    {
      DNA::PropertyWrapper::GetPropertyInfo(v5, &result);
      v8 = result.Size;
      if ( result.States.p )
        operator delete[](result.States.p);
      result.States.p = 0i64;
      *(_QWORD *)&result.States.size = 0i64;
    }
    DNA::DUIDNAWidget::GetDisplayName(v6, &text, v4);
    if ( v8 <= 1
      || (v9 = text.mData,
          v10 = DNA::DUIDNAWidget::GetExpandedState(v6, v5, 0),
          (unsigned __int8)UFG::DUIContext::Collapsible(v6->mContext, v9, v10)) )
    {
      for ( i = 0; i < v8; ++i )
      {
        UFG::DUIContext::BeginGridLayout(v6->mContext, 2, 1, 4);
        UFG::DUIContext::BeginIndent(v6->mContext);
        if ( v8 <= 1i64 )
        {
          UFG::qString::qString(&v17, &text);
          v7 |= 2u;
        }
        else
        {
          v12 = UFG::qString::FormatEx(&v18, "%s[%d]", text.mData, (unsigned int)i);
          v7 |= 1u;
        }
        UFG::qString::qString((UFG::qString *)&result, v12);
        if ( v7 & 2 )
        {
          v7 &= 0xFFFFFFFD;
          UFG::qString::~qString(&v17);
        }
        if ( v7 & 1 )
        {
          v7 &= 0xFFFFFFFE;
          UFG::qString::~qString(&v18);
        }
        UFG::DUIContext::Label(v6->mContext, name);
        UFG::DUIContext::EndIndent(v6->mContext);
        LODWORD(result.States.p) = i;
        DNA::DUIDNAWidget::AddBasicType(v6, v5, v4, field_typea);
        UFG::DUIContext::EndLayoutHorizontal(v6->mContext);
        UFG::qString::~qString((UFG::qString *)&result);
      }
    }
    UFG::qString::~qString(&text);
  }
}

// File Line: 357
// RVA: 0x1B2870
void __fastcall DNA::DUIDNAWidget::AddColourType(DNA::DUIDNAWidget *this, DNA::PropertyBagWrapper *field_bag)
{
  DNA::PropertyBagWrapper *v2; // rdi
  DNA::DUIDNAWidget *v3; // rbx
  DNA::PropertyWrapper *v4; // rax
  DNA::PropertyWrapper *v5; // rax
  DNA::PropertyWrapper *v6; // rax
  DNA::PropertyWrapper *v7; // rax
  UFG::DUIContext *v8; // rcx
  DNA::PropertyWrapper *v9; // rax
  DNA::PropertyWrapper *v10; // rax
  DNA::PropertyWrapper *v11; // rax
  DNA::PropertyWrapper *v12; // rax
  float v13; // [rsp+20h] [rbp-28h]
  UFG::qColour current_colour_rgb; // [rsp+28h] [rbp-20h]
  float v; // [rsp+50h] [rbp+8h]
  float v16; // [rsp+60h] [rbp+18h]
  float v17; // [rsp+68h] [rbp+20h]

  v2 = field_bag;
  v3 = this;
  v = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  v13 = 0.0;
  v4 = DNA::PropertyBagWrapper::GetProperty(field_bag, "r");
  DNA::PropertyWrapper::Get(v4, 0, &v, 0);
  v5 = DNA::PropertyBagWrapper::GetProperty(v2, "g");
  DNA::PropertyWrapper::Get(v5, 0, &v16, 0);
  v6 = DNA::PropertyBagWrapper::GetProperty(v2, "b");
  DNA::PropertyWrapper::Get(v6, 0, &v17, 0);
  v7 = DNA::PropertyBagWrapper::GetProperty(v2, "a");
  DNA::PropertyWrapper::Get(v7, 0, &v13, 0);
  v8 = v3->mContext;
  current_colour_rgb.r = v;
  current_colour_rgb.g = v16;
  current_colour_rgb.b = v17;
  current_colour_rgb.a = v13;
  if ( (unsigned __int8)UFG::DUIContext::ColourPicker(v8, &customWorldMapCaption, &current_colour_rgb, 1) )
  {
    v9 = DNA::PropertyBagWrapper::GetProperty(v2, "r");
    DNA::PropertyWrapper::Set(v9, 0, current_colour_rgb.r, 0);
    v10 = DNA::PropertyBagWrapper::GetProperty(v2, "g");
    DNA::PropertyWrapper::Set(v10, 0, current_colour_rgb.g, 0);
    v11 = DNA::PropertyBagWrapper::GetProperty(v2, "b");
    DNA::PropertyWrapper::Set(v11, 0, current_colour_rgb.b, 0);
    v12 = DNA::PropertyBagWrapper::GetProperty(v2, "a");
    DNA::PropertyWrapper::Set(v12, 0, current_colour_rgb.a, 0);
  }
}

// File Line: 378
// RVA: 0x1B13C0
void __fastcall DNA::DUIDNAWidget::AddBasicType(DNA::DUIDNAWidget *this, DNA::PropertyWrapper *property_wrapper, UFG::qReflectField *field, UFG::qReflectType *field_type)
{
  UFG::qReflectType *v4; // rbx
  UFG::qReflectField *v5; // r14
  DNA::PropertyWrapper *v6; // rsi
  DNA::DUIDNAWidget *v7; // rdi
  __int64 v8; // r15
  signed int v9; // ecx
  UFG::qString *v10; // rax
  char v11; // bl
  UFG::qString *v12; // rax
  char v13; // bl
  UFG::qString *v14; // rax
  char v15; // bl
  UFG::qString *v16; // rax
  char v17; // bl
  UFG::qString *v18; // rax
  signed int v19; // ebx
  char v20; // bl
  bool v21; // al
  UFG::ReflectionDB *v22; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v23; // rax
  unsigned int v24; // er14
  UFG::qTree64Base::BaseNode *v25; // rbx
  signed __int64 v26; // r12
  char *v27; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v29; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v30; // rax
  int v31; // eax
  UFG::qNode<UFG::qString,UFG::qString> *v32; // r8
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v35; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v36; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+38h] [rbp-90h]
  UFG::qString current_value; // [rsp+48h] [rbp-80h]
  DNA::PropertyInfo result; // [rsp+70h] [rbp-58h]
  UFG::qString v41; // [rsp+A8h] [rbp-20h]
  UFG::qString v42; // [rsp+D0h] [rbp+8h]
  UFG::qString v43; // [rsp+F8h] [rbp+30h]
  UFG::qString v44; // [rsp+120h] [rbp+58h]
  UFG::qString v45; // [rsp+148h] [rbp+80h]
  UFG::qString v46; // [rsp+170h] [rbp+A8h]
  UFG::qString v47; // [rsp+198h] [rbp+D0h]
  UFG::qString v48; // [rsp+1C0h] [rbp+F8h]
  UFG::qString v49; // [rsp+220h] [rbp+158h]
  unsigned int index; // [rsp+258h] [rbp+190h]

  current_value.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)-2i64;
  v4 = field_type;
  v5 = field;
  v6 = property_wrapper;
  v7 = this;
  DNA::PropertyWrapper::GetPropertyInfo(property_wrapper, &result);
  v8 = index;
  if ( !*((_DWORD *)&current_value.mPrev->mPrev + index) )
    UFG::DUIContext::PushColour(v7->mContext, 0, &UFG::qColour::Grey);
  v9 = v6->mSchemaField->mType;
  if ( v9 > 224407815 )
  {
    switch ( v9 )
    {
      case 826535573:
        UFG::qString::qString(&current_value);
        DNA::PropertyWrapper::Get(v6, v8, &current_value, 0);
        if ( (v6->mSchemaField->mReflectionField->mFlags >> 2) & 1 )
        {
          *(float *)&index = 0.0;
          options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
          options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
          v22 = UFG::ReflectionDB::Instance();
          v23 = UFG::ReflectionDB::GetEnum(v22, v4->mName);
          if ( v23 )
          {
            v24 = 0;
            v25 = v23[1].mTree.mHead.mChildren[0];
            v26 = (signed __int64)&v23[1].mTree.mHead.mParent;
            if ( v25 != (UFG::qTree64Base::BaseNode *)&v23[1].mTree.mHead.mParent )
            {
              while ( 1 )
              {
                v27 = (char *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
                v49.mData = v27;
                if ( v27 )
                {
                  UFG::qString::qString((UFG::qString *)v27, (const char *)v25->mChildren[0]);
                  v29 = v28;
                }
                else
                {
                  v29 = 0i64;
                }
                v30 = options.mNode.mPrev;
                options.mNode.mPrev->mNext = v29;
                v29->mPrev = v30;
                v29->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
                options.mNode.mPrev = v29;
                if ( !(unsigned int)UFG::qStringCompare((const char *)v25->mChildren[0], current_value.mData, -1) )
                  break;
                ++v24;
                v25 = v25->mParent;
                if ( v25 == (UFG::qTree64Base::BaseNode *)v26 )
                  goto LABEL_79;
              }
              index = v24;
            }
          }
LABEL_79:
          if ( UFG::DUIContext::ComboBox(v7->mContext, (int *)&index, &options, 0i64, 0xFFFFFFFF) )
          {
            v31 = 0;
            v32 = options.mNode.mNext;
            if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options )
            {
              while ( v31 != index )
              {
                ++v31;
                v32 = v32->mNext;
                if ( v32 == (UFG::qNode<UFG::qString,UFG::qString> *)&options )
                  goto LABEL_85;
              }
              DNA::PropertyWrapper::Set(v6, v8, (const char *)v32[1].mNext, 0);
            }
          }
LABEL_85:
          for ( i = (UFG::qString *)options.mNode.mNext;
                (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
                i = (UFG::qString *)options.mNode.mNext )
          {
            v34 = i->mPrev;
            v35 = i->mNext;
            v34->mNext = v35;
            v35->mPrev = v34;
            i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
            i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
            UFG::qString::~qString(i);
            operator delete[](i);
          }
          v36 = options.mNode.mPrev;
          v37 = options.mNode.mNext;
          options.mNode.mPrev->mNext = options.mNode.mNext;
          v37->mPrev = v36;
          options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
          options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
        }
        else if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &current_value, 0i64, 1, 0i64, 0xFFFFFFFF) )
        {
          DNA::PropertyWrapper::Set(v6, v8, current_value.mData, 0);
        }
        goto LABEL_90;
      case 1138723642:
        LOBYTE(index) = 0;
        DNA::PropertyWrapper::Get(v6, v8, (bool *)&index, 0);
        v20 = index;
        v21 = UFG::DUIContext::Checkbox(v7->mContext, &customWorldMapCaption, (bool *)&index);
        LOBYTE(index) = v21;
        if ( v20 != v21 )
          DNA::PropertyWrapper::Set(v6, v8, v21, 0);
        break;
      case 1208522079:
        *(float *)&index = 0.0;
        DNA::PropertyWrapper::Get(v6, v8, (float *)&index, 0);
        v49.mStringHash32 = 0;
        LODWORD(v49.mData) = 0;
        if ( !DNA::HasRange(
                v7->mTypeStack.p[v7->mTypeStack.size - 1],
                v5,
                (float *)&v49.mStringHash32,
                (float *)&v49.mData) )
        {
          if ( v7->mActiveEdit == v6 )
          {
            UFG::qString::qString(&v48, &v7->mEditValue);
            v19 = 256;
          }
          else
          {
            v18 = UFG::qString::FormatEx(&v46, "%f", index);
            v19 = 512;
          }
          UFG::qString::qString(&current_value, v18);
          if ( _bittest(&v19, 9u) )
          {
            v19 &= 0xFFFFFDFF;
            UFG::qString::~qString(&v46);
          }
          if ( _bittest(&v19, 8u) )
            UFG::qString::~qString(&v48);
          if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &current_value, 0i64, 1, 0i64, 0xFFFFFFFF) )
          {
            v7->mActiveEdit = v6;
            UFG::qString::Set(&v7->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
            *(float *)&index = UFG::qToFloat(v7->mEditValue.mData, *(float *)&index);
            DNA::PropertyWrapper::Set(v6, v8, *(float *)&index, 0);
          }
          goto LABEL_90;
        }
        if ( (unsigned __int8)UFG::DUIContext::Slider(
                                v7->mContext,
                                &customWorldMapCaption,
                                (float *)&index,
                                *(float *)&v49.mStringHash32) )
          DNA::PropertyWrapper::Set(v6, v8, *(float *)&index, 0);
        break;
    }
  }
  else
  {
    switch ( v9 )
    {
      case 224407815:
        v49.mData = 0i64;
        DNA::PropertyWrapper::Get(v6, v8, (__int64 *)&v49.mData, 0);
        if ( v7->mActiveEdit == v6 )
        {
          UFG::qString::qString(&v44, &v7->mEditValue);
          v17 = 4;
        }
        else
        {
          v16 = UFG::qString::FormatEx(&v42, "%d", v49.mData);
          v17 = 8;
        }
        UFG::qString::qString(&current_value, v16);
        if ( v17 & 8 )
        {
          v17 &= 0xF7u;
          UFG::qString::~qString(&v42);
        }
        if ( v17 & 4 )
          UFG::qString::~qString(&v44);
        if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &current_value, 0i64, 1, 0i64, 0xFFFFFFFF) )
        {
          v7->mActiveEdit = v6;
          UFG::qString::Set(&v7->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
          v49.mData = (char *)UFG::qToInt64(v7->mEditValue.mData, (__int64)v49.mData);
          DNA::PropertyWrapper::Set(v6, v8, (__int64)v49.mData, 0);
        }
        goto LABEL_90;
      case -2133091136:
        *(float *)&index = 0.0;
        DNA::PropertyWrapper::Get(v6, v8, (int *)&index, 0);
        v49.mStringHash32 = 0;
        LODWORD(v49.mData) = 0;
        if ( !DNA::HasRange(v7->mTypeStack.p[v7->mTypeStack.size - 1], v5, (int *)&v49.mStringHash32, (int *)&v49.mData) )
        {
          if ( v7->mActiveEdit == v6 )
          {
            UFG::qString::qString((UFG::qString *)&result.States.p, &v7->mEditValue);
            v15 = 1;
          }
          else
          {
            v14 = UFG::qString::FormatEx(&v47, "%d", index);
            v15 = 2;
          }
          UFG::qString::qString(&current_value, v14);
          if ( v15 & 2 )
          {
            v15 &= 0xFDu;
            UFG::qString::~qString(&v47);
          }
          if ( v15 & 1 )
            UFG::qString::~qString((UFG::qString *)&result.States.p);
          if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &current_value, 0i64, 1, 0i64, 0xFFFFFFFF) )
          {
            v7->mActiveEdit = v6;
            UFG::qString::Set(&v7->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
            index = UFG::qToInt32(v7->mEditValue.mData, index);
            DNA::PropertyWrapper::Set(v6, v8, index, 0);
          }
          goto LABEL_90;
        }
        if ( (unsigned __int8)UFG::DUIContext::Slider(
                                v7->mContext,
                                &customWorldMapCaption,
                                (int *)&index,
                                v49.mStringHash32) )
          DNA::PropertyWrapper::Set(v6, v8, index, 0);
        break;
      case -2067794966:
        *(float *)&index = 0.0;
        DNA::PropertyWrapper::Get(v6, v8, &index, 0);
        if ( v7->mActiveEdit == v6 )
        {
          UFG::qString::qString(&v43, &v7->mEditValue);
          v13 = 16;
        }
        else
        {
          v12 = UFG::qString::FormatEx((UFG::qString *)((char *)&current_value + 16), "%d", index);
          v13 = 32;
        }
        UFG::qString::qString(&current_value, v12);
        if ( v13 & 0x20 )
        {
          v13 &= 0xDFu;
          UFG::qString::~qString((UFG::qString *)((char *)&current_value + 16));
        }
        if ( v13 & 0x10 )
          UFG::qString::~qString(&v43);
        if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &current_value, 0i64, 1, 0i64, 0xFFFFFFFF) )
        {
          v7->mActiveEdit = v6;
          UFG::qString::Set(&v7->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
          index = UFG::qToUInt32(v7->mEditValue.mData, index);
          DNA::PropertyWrapper::Set(v6, v8, index, 0);
        }
        goto LABEL_90;
      case 151281197:
        v49.mData = 0i64;
        DNA::PropertyWrapper::Get(v6, v8, (unsigned __int64 *)&v49.mData, 0);
        if ( v7->mActiveEdit == v6 )
        {
          UFG::qString::qString(&v41, &v7->mEditValue);
          v11 = 64;
        }
        else
        {
          v10 = UFG::qString::FormatEx(&v45, "%d", v49.mData);
          v11 = -128;
        }
        UFG::qString::qString(&current_value, v10);
        if ( v11 < 0 )
        {
          v11 &= 0x7Fu;
          UFG::qString::~qString(&v45);
        }
        if ( v11 & 0x40 )
          UFG::qString::~qString(&v41);
        if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &current_value, 0i64, 1, 0i64, 0xFFFFFFFF) )
        {
          v7->mActiveEdit = v6;
          UFG::qString::Set(&v7->mEditValue, current_value.mData, current_value.mLength, 0i64, 0);
          v49.mData = (char *)UFG::qToUInt64(v7->mEditValue.mData, (unsigned __int64)v49.mData);
          DNA::PropertyWrapper::Set(v6, v8, (unsigned __int64)v49.mData, 0);
        }
LABEL_90:
        UFG::qString::~qString(&current_value);
        break;
    }
  }
  if ( v7->mActiveEdit == v6 && v7->mContext->mCurrentID != v7->mContext->mFocusedID )
    v7->mActiveEdit = 0i64;
  if ( !*((_DWORD *)&current_value.mPrev->mPrev + v8) )
    UFG::DUIContext::PopColour(v7->mContext, 0);
  if ( current_value.mPrev )
    operator delete[](current_value.mPrev);
}

// File Line: 571
// RVA: 0x1B59F0
void __fastcall DNA::DUIDNAInspector::UpdateUI(DNA::DUIDNAInspector *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  DNA::DUIDNAInspector *v3; // rbx
  __int64 v4; // rax
  bool v5; // zf
  DNA::PropertyBagWrapper *v6; // rdx
  __int64 v7; // rax
  AMD_HD3D *v8; // rax

  v2 = dui;
  v3 = this;
  DNA::Database::Instance();
  *(_BYTE *)(v4 + 48) = 1;
  UFG::DUIContext::BeginScrollView(v2, &v3->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(v2);
  v5 = v3->mWidget.mProperties == 0i64;
  v3->mWidget.mContext = v2;
  if ( !v5 )
  {
    v6 = v3->mWidget.mWrapper;
    if ( v6 )
      DNA::DUIDNAWidget::PopulateUIRecursive(&v3->mWidget, v6, 0i64);
  }
  v3->mWidget.mContext = 0i64;
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndScrollView(v2);
  DNA::Database::Instance();
  *(_BYTE *)(v7 + 48) = 0;
  DNA::Database::Instance();
  _(v8);
}

// File Line: 613
// RVA: 0x1AFEB0
void __fastcall DNA::DUIReflectWidget::DUIReflectWidget(DNA::DUIReflectWidget *this)
{
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *v1; // [rsp+48h] [rbp+10h]

  this->vfptr = (UFG::qReflectVisitorVtbl *)&UFG::qReflectVisitor::`vftable;
  this->mTrackedObjects.p = 0i64;
  *(_QWORD *)&this->mTrackedObjects.size = 0i64;
  this->mPatches.p = 0i64;
  *(_QWORD *)&this->mPatches.size = 0i64;
  this->mArrays.p = 0i64;
  *(_QWORD *)&this->mArrays.size = 0i64;
  this->vfptr = (UFG::qReflectVisitorVtbl *)&DNA::DUIReflectWidget::`vftable;
  this->mObject = 0i64;
  this->mFieldStack.p = 0i64;
  *(_QWORD *)&this->mFieldStack.size = 0i64;
  this->mTypeStack.p = 0i64;
  *(_QWORD *)&this->mTypeStack.size = 0i64;
  this->mArrayIndices.p = 0i64;
  *(_QWORD *)&this->mArrayIndices.size = 0i64;
  this->mExpandState.p = 0i64;
  *(_QWORD *)&this->mExpandState.size = 0i64;
  v1 = &this->mSubObjects;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
  this->mActiveEdit = 0i64;
  UFG::qString::qString(&this->mEditValue);
}

// File Line: 617
// RVA: 0x1B0900
void __fastcall DNA::DUIReflectWidget::~DUIReflectWidget(DNA::DUIReflectWidget *this)
{
  DNA::DUIReflectWidget *v1; // rdi
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *v2; // rbx
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *v3; // rcx
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *v4; // rax
  DNA::DUIReflectWidget::ExpandState *v5; // rcx
  unsigned int *v6; // rcx
  UFG::qReflectType **v7; // rcx
  UFG::qReflectField **v8; // rcx

  v1 = this;
  this->vfptr = (UFG::qReflectVisitorVtbl *)&DNA::DUIReflectWidget::`vftable;
  v2 = &this->mSubObjects;
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0>::DeleteNodes(&this->mSubObjects);
  UFG::qString::~qString(&v1->mEditValue);
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0>::DeleteNodes(v2);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v5 = v1->mExpandState.p;
  if ( v5 )
    operator delete[](v5);
  v1->mExpandState.p = 0i64;
  *(_QWORD *)&v1->mExpandState.size = 0i64;
  v6 = v1->mArrayIndices.p;
  if ( v6 )
    operator delete[](v6);
  v1->mArrayIndices.p = 0i64;
  *(_QWORD *)&v1->mArrayIndices.size = 0i64;
  v7 = v1->mTypeStack.p;
  if ( v7 )
    operator delete[](v7);
  v1->mTypeStack.p = 0i64;
  *(_QWORD *)&v1->mTypeStack.size = 0i64;
  v8 = v1->mFieldStack.p;
  if ( v8 )
    operator delete[](v8);
  v1->mFieldStack.p = 0i64;
  *(_QWORD *)&v1->mFieldStack.size = 0i64;
  UFG::qReflectVisitor::~qReflectVisitor((UFG::qReflectVisitor *)&v1->vfptr);
}

// File Line: 630
// RVA: 0x1B3B80
bool __fastcall DNA::DUIReflectWidget::DiscoverObjectField(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *object_data)
{
  unsigned int v4; // eax

  v4 = field->mFlags;
  return (v4 & 0x80u) == 0 && !(v4 & 8);
}

// File Line: 641
// RVA: 0x1B3470
void __fastcall DNA::DUIReflectWidget::BeginField(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *object_data)
{
  __int64 v4; // rsi
  UFG::qArray<UFG::qReflectField const *,0> *v5; // rdi
  UFG::qReflectField *v6; // rbp
  unsigned int v7; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  UFG::qReflectField **v10; // rax

  v4 = this->mFieldStack.size;
  v5 = &this->mFieldStack;
  v6 = field;
  v7 = this->mFieldStack.capacity;
  v8 = v4 + 1;
  if ( (signed int)v4 + 1 > v7 )
  {
    if ( v7 )
      v9 = 2 * v7;
    else
      v9 = 1;
    for ( ; v9 < v8; v9 *= 2 )
      ;
    if ( v9 <= 2 )
      v9 = 2;
    if ( v9 - v8 > 0x10000 )
      v9 = v4 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mFieldStack,
      v9,
      "qArray.Add");
  }
  v10 = v5->p;
  v5->size = v8;
  v10[v4] = v6;
}

// File Line: 646
// RVA: 0x1B3CF0
void __fastcall DNA::DUIReflectWidget::EndDiscoverField(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *object_data)
{
  unsigned int v4; // eax

  v4 = this->mFieldStack.size;
  if ( v4 > 1 )
    this->mFieldStack.size = v4 - 1;
  else
    this->mFieldStack.size = 0;
}

// File Line: 661
// RVA: 0x1B3590
char __fastcall DNA::DUIReflectWidget::BeginObjectField(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *object_data)
{
  const char *v4; // r14
  UFG::qReflectType *v5; // rbp
  UFG::qReflectField *v6; // rsi
  DNA::DUIReflectWidget *v7; // rdi
  bool *v9; // rbx
  unsigned int v10; // eax
  bool *v11; // rbx
  bool v12; // bl
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v4 = object_data;
  v5 = field_type;
  v6 = field;
  v7 = this;
  if ( field->mFlags & 2 )
    return 1;
  if ( (unsigned __int8)DNA::HasEditor(field, "ColourPicker") )
  {
    v9 = DNA::DUIReflectWidget::GetExpandedState(v7, v5, v6);
    DNA::DUIReflectWidget::GetDisplayName(v7, &result, v6);
    UFG::DUIContext::Collapsible(v7->mContext, result.mData, v9);
    if ( *v9 )
      ((void (__fastcall *)(DNA::DUIReflectWidget *, UFG::qReflectField *, UFG::qReflectType *, const char *, signed __int64))v7->vfptr->BeginBytes)(
        v7,
        v6,
        v5,
        v4,
        -2i64);
    UFG::qString::~qString(&result);
    return 0;
  }
  v10 = v6->mFlags;
  if ( (v10 & 0x80u) != 0 || v10 & 8 )
  {
    ((void (__fastcall *)(DNA::DUIReflectWidget *, UFG::qReflectField *, UFG::qReflectType *, const char *, signed __int64))v7->vfptr->BeginBytes)(
      v7,
      v6,
      v5,
      v4,
      -2i64);
    return 0;
  }
  if ( DNA::IsHidden(v7->mTypeStack.p[v7->mTypeStack.size - 1], v6) )
    return 0;
  v11 = DNA::DUIReflectWidget::GetExpandedState(v7, v5, v6);
  DNA::DUIReflectWidget::GetDisplayName(v7, &result, v6);
  v12 = UFG::DUIContext::Collapsible(v7->mContext, result.mData, v11);
  if ( v12 )
    UFG::DUIContext::BeginIndent(v7->mContext);
  UFG::qString::~qString(&result);
  return v12;
}

// File Line: 706
// RVA: 0x1B3500
void __fastcall DNA::DUIReflectWidget::BeginObject(DNA::DUIReflectWidget *this, UFG::qReflectType *field_type, const char *object_data)
{
  __int64 v3; // rsi
  UFG::qArray<UFG::qReflectType const *,0> *v4; // rdi
  UFG::qReflectType *v5; // rbp
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  UFG::qReflectType **v9; // rax

  v3 = this->mTypeStack.size;
  v4 = &this->mTypeStack;
  v5 = field_type;
  v6 = this->mTypeStack.capacity;
  v7 = v3 + 1;
  if ( (signed int)v3 + 1 > v6 )
  {
    if ( v6 )
      v8 = 2 * v6;
    else
      v8 = 1;
    for ( ; v8 < v7; v8 *= 2 )
      ;
    if ( v8 <= 2 )
      v8 = 2;
    if ( v8 - v7 > 0x10000 )
      v8 = v3 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mTypeStack,
      v8,
      "qArray.Add");
  }
  v9 = v4->p;
  v4->size = v7;
  v9[v3] = v5;
}

// File Line: 711
// RVA: 0x1B3D10
void __fastcall DNA::DUIReflectWidget::EndObject(DNA::DUIReflectWidget *this, UFG::qReflectType *field_type, const char *object_data)
{
  unsigned int v3; // eax

  v3 = this->mTypeStack.size;
  if ( v3 > 1 )
    this->mTypeStack.size = v3 - 1;
  else
    this->mTypeStack.size = 0;
}

// File Line: 716
// RVA: 0x1B3D30
void __fastcall DNA::DUIReflectWidget::EndObjectField(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *object_data)
{
  if ( !(field->mFlags & 2) )
    UFG::DUIContext::EndIndent(this->mContext);
}

// File Line: 724
// RVA: 0x1B3BA0
bool __fastcall DNA::DUIReflectWidget::DiscoverPointerField(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *object_data)
{
  const char *v4; // rax
  UFG::qReflectType *v5; // rbp
  UFG::qReflectField *v6; // rsi
  DNA::DUIReflectWidget *v7; // r13
  unsigned __int64 v8; // r15
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *v9; // r12
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // r14
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *v12; // rbx
  UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *v13; // rdi
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *v16; // rax
  const char *v18; // [rsp+88h] [rbp+20h]

  v18 = object_data;
  v4 = object_data;
  v5 = field_type;
  v6 = field;
  v7 = this;
  v8 = 0i64;
  if ( field->mArrayLength )
  {
    do
    {
      if ( v5->mFlags & 0x10 )
      {
        v9 = *(UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> **)&v4[8 * v8];
        v10 = DNA::DUIReflectWidget::GetIDForObject(v7);
        v11 = v10;
        v12 = (UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *)v7->mSubObjects.mNode.mNext;
        v13 = &v7->mSubObjects;
        if ( v12 == &v7->mSubObjects )
        {
LABEL_8:
          v14 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
          v12 = (UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *)v14;
          if ( v14 )
          {
            v14->mNext = v14;
            v14[1].mNext = v14;
            v14[2].mNext = 0i64;
            v14[3].mNext = 0i64;
            v14[4].mNext = 0i64;
            v14[5].mNext = 0i64;
          }
          else
          {
            v12 = 0i64;
          }
          v12[1].mNode.mNext = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v6;
          v12[1].mNode.mPrev = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v5;
          v15 = UFG::qMalloc(0xC8ui64, UFG::gGlobalNewName, 0i64);
          if ( v15 )
            DNA::DUIReflectWidget::DUIReflectWidget((DNA::DUIReflectWidget *)v15);
          v12[2].mNode.mNext = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v15;
          v12[2].mNode.mPrev = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v11;
          v16 = v13->mNode.mPrev;
          v16->mNext = &v12->mNode;
          v12->mNode.mPrev = v16;
          v12->mNode.mNext = &v13->mNode;
          v13->mNode.mPrev = &v12->mNode;
        }
        else
        {
          while ( (UFG::qReflectField *)v12[1].mNode.mNext != v6
               || (UFG::qReflectType *)v12[1].mNode.mPrev != v5
               || v12[2].mNode.mPrev != (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v10 )
          {
            v12 = (UFG::qList<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject,1,0> *)v12->mNode.mNext;
            if ( v12 == v13 )
              goto LABEL_8;
          }
        }
        v12[2].mNode.mNext[4].mPrev = v9;
        v4 = v18;
      }
      ++v8;
    }
    while ( v8 < v6->mArrayLength );
  }
  return 0;
}

// File Line: 740
// RVA: 0x1B36F0
bool __fastcall DNA::DUIReflectWidget::BeginPointerField(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *object_data)
{
  UFG::qReflectType *v4; // rbp
  UFG::qReflectField *v5; // rsi
  DNA::DUIReflectWidget *v6; // rbx
  unsigned __int64 v7; // rdi
  DNA::DUIReflectWidget::SubObject *v8; // r14
  bool *v9; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v4 = field_type;
  v5 = field;
  v6 = this;
  v7 = 0i64;
  if ( field->mArrayLength )
  {
    do
    {
      if ( v4->mFlags & 0x10 )
      {
        v8 = DNA::DUIReflectWidget::GetSubObject(v6, v4, v5);
        DNA::DUIReflectWidget::GetDisplayName(v6, &result, v5);
        v9 = DNA::DUIReflectWidget::GetExpandedState(v6, v4, v5);
        if ( (unsigned __int8)UFG::DUIContext::Collapsible(v6->mContext, result.mData, v9) )
        {
          UFG::DUIContext::BeginIndent(v6->mContext);
          DNA::DUIReflectWidget::UpdateUI(v8->mWidget, v6->mContext);
          UFG::DUIContext::EndIndent(v6->mContext);
        }
        UFG::qString::~qString(&result);
      }
      ++v7;
    }
    while ( v7 < v5->mArrayLength );
  }
  return 0;
}

// File Line: 762
// RVA: 0x1B3870
bool __fastcall DNA::DUIReflectWidget::DiscoverArrayField(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *field_data)
{
  unsigned int v4; // edx
  __int64 v5; // rsi
  unsigned int v6; // ebx
  const char *v7; // r14
  UFG::qReflectType *v8; // rbp
  DNA::DUIReflectWidget *v9; // rdi
  unsigned int v10; // edx
  unsigned int *v11; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v12; // rbx
  UFG::ReflectionDB *v13; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v14; // rax
  UFG::qReflectField *v15; // r8
  unsigned __int64 v16; // r10
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v17; // r11
  UFG::qReflectType *v18; // r9
  const char *v19; // r13
  unsigned int v20; // ebp
  unsigned int v21; // er15
  __int64 v22; // r12
  __int64 v23; // r14
  unsigned int v24; // ebx
  unsigned int v25; // esi
  unsigned int v26; // ebx
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // rax
  unsigned int *v29; // rbp
  signed __int64 v30; // r9
  signed __int64 v31; // r8
  unsigned int *v32; // rax
  UFG::qReflectObject *v33; // rbx
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v37; // [rsp+20h] [rbp-68h]
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v38; // [rsp+28h] [rbp-60h]
  unsigned __int64 v39; // [rsp+30h] [rbp-58h]
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v40; // [rsp+38h] [rbp-50h]
  DNA::DUIReflectWidget *v41; // [rsp+90h] [rbp+8h]
  UFG::qReflectField *fielda; // [rsp+98h] [rbp+10h]
  UFG::qReflectType *type; // [rsp+A0h] [rbp+18h]
  const char *v44; // [rsp+A8h] [rbp+20h]

  v44 = field_data;
  type = field_type;
  fielda = field;
  v41 = this;
  v4 = this->mArrayIndices.capacity;
  v5 = this->mArrayIndices.size;
  v6 = v5 + 1;
  v7 = field_data;
  v8 = field_type;
  v9 = this;
  if ( (signed int)v5 + 1 > v4 )
  {
    if ( v4 )
      v10 = 2 * v4;
    else
      v10 = 1;
    for ( ; v10 < v6; v10 *= 2 )
      ;
    if ( v10 <= 4 )
      v10 = 4;
    if ( v10 - v6 > 0x10000 )
      v10 = v5 + 65537;
    UFG::qArray<long,0>::Reallocate(&this->mArrayIndices, v10, "qArray.Add");
  }
  v11 = v9->mArrayIndices.p;
  v9->mArrayIndices.size = v6;
  v11[v5] = 0;
  v12 = v8->mOrderedFields.mNode.mNext;
  v40 = v8->mOrderedFields.mNode.mNext;
  v13 = UFG::ReflectionDB::Instance();
  v14 = UFG::ReflectionDB::GetType(v13, (const char *)v12[4].mNext);
  v15 = fielda;
  v16 = 0i64;
  v17 = v14;
  v38 = v14;
  v39 = 0i64;
  if ( fielda->mArrayLength )
  {
    v18 = type;
    do
    {
      v9->mArrayIndices.p[v9->mArrayIndices.size - 1] = v16;
      v19 = &v7[v18->mNumBytes * v16];
      v20 = *((_DWORD *)v19 + 2);
      v37 = v20;
      if ( v20 )
      {
        if ( BYTE4(v17[1].mTree.mHead.mNeighbours[0]) & 0x10 )
        {
          v21 = 0;
          if ( v20 )
          {
            v22 = 0i64;
            do
            {
              v23 = v9->mArrayIndices.size;
              v24 = v9->mArrayIndices.capacity;
              v25 = v23 + 1;
              if ( (signed int)v23 + 1 > v24 )
              {
                if ( v24 )
                  v26 = 2 * v24;
                else
                  v26 = 1;
                for ( ; v26 < v25; v26 *= 2 )
                  ;
                if ( v26 <= 4 )
                  v26 = 4;
                if ( v26 - v25 > 0x10000 )
                  v26 = v23 + 65537;
                if ( v26 != (_DWORD)v23 )
                {
                  v27 = 4i64 * v26;
                  if ( !is_mul_ok(v26, 4ui64) )
                    v27 = -1i64;
                  v28 = UFG::qMalloc(v27, "qArray.Add", 0i64);
                  v29 = (unsigned int *)v28;
                  if ( v9->mArrayIndices.p )
                  {
                    v30 = 0i64;
                    if ( v9->mArrayIndices.size )
                    {
                      do
                      {
                        v31 = v30;
                        v30 = (unsigned int)(v30 + 1);
                        *(_DWORD *)((char *)&v28->mNext + v31 * 4) = v9->mArrayIndices.p[v31];
                      }
                      while ( (unsigned int)v30 < v9->mArrayIndices.size );
                    }
                    operator delete[](v9->mArrayIndices.p);
                  }
                  v15 = fielda;
                  v18 = type;
                  v17 = v38;
                  v9->mArrayIndices.p = v29;
                  v20 = v37;
                  v9->mArrayIndices.capacity = v26;
                }
              }
              v32 = v9->mArrayIndices.p;
              v9->mArrayIndices.size = v25;
              v32[v23] = v21;
              if ( (_QWORD)v40[7].mPrev & 0x4000 )
                v33 = *(UFG::qReflectObject **)(v22 + *(_QWORD *)v19);
              else
                v33 = (UFG::qReflectObject *)(*(_QWORD *)v19
                                            + (~(LODWORD(v17[1].mTree.mHead.mNeighbours[0]) - 1i64) & (LODWORD(v17[1].mTree.mHead.mNeighbours[0]) + v21 * (_QWORD)v17[1].mTree.mHead.mChildren[1] - 1i64)));
              DNA::DUIReflectWidget::GetSubObject(v41, v18, v15)->mWidget->mObject = v33;
              v34 = v9->mArrayIndices.size;
              if ( v34 > 1 )
                v9->mArrayIndices.size = v34 - 1;
              else
                v9->mArrayIndices.size = 0;
              v15 = fielda;
              v18 = type;
              v17 = v38;
              ++v21;
              v22 += 8i64;
            }
            while ( v21 < v20 );
            v16 = v39;
            v7 = v44;
          }
        }
      }
      v39 = ++v16;
    }
    while ( v16 < v15->mArrayLength );
  }
  v35 = v9->mArrayIndices.size;
  if ( v35 > 1 )
    v9->mArrayIndices.size = v35 - 1;
  else
    v9->mArrayIndices.size = 0;
  return 0;
}

// File Line: 814
// RVA: 0x1B2BF0
bool __fastcall DNA::DUIReflectWidget::BeginArrayField(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *field_data)
{
  UFG::qReflectType *v4; // r15
  UFG::qReflectField *v5; // r14
  DNA::DUIReflectWidget *v6; // rbp
  UFG::qArray<unsigned long,0> *v7; // rdi
  __int64 v8; // rsi
  unsigned int v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // edx
  UFG::qReflectField *v12; // r15
  UFG::ReflectionDB *v13; // rax
  UFG::qReflectType *v14; // r13
  unsigned __int64 v15; // r12
  UFG::qReflectType *v16; // r9
  const char *v17; // rdx
  unsigned int v18; // er12
  unsigned int v19; // eax
  unsigned int v20; // er15
  __int64 v21; // r12
  __int64 v22; // r13
  unsigned int v23; // esi
  unsigned int v24; // ebx
  unsigned int v25; // ebx
  unsigned __int64 v26; // rax
  UFG::allocator::free_link *v27; // rax
  unsigned int *v28; // r14
  __int64 v29; // r9
  __int64 v30; // rbx
  DNA::DUIReflectWidget::SubObject *v31; // rsi
  unsigned __int64 v32; // rbx
  UFG::ReflectionDB *v33; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v34; // rax
  bool *v35; // rax
  UFG::qString *v36; // rcx
  DNA::DUIReflectWidget::SubObject *v37; // rbx
  bool *v38; // rax
  unsigned int v39; // esi
  __int64 v40; // r15
  __int64 v41; // r14
  unsigned int v42; // ebx
  unsigned int v43; // edx
  unsigned int v44; // edx
  UFG::qColour *v45; // rbx
  bool *v46; // rax
  char v47; // al
  UFG::DUIContext *v48; // rcx
  unsigned int v49; // esi
  __int64 v50; // r14
  const char *v51; // rbx
  const char *v53; // [rsp+30h] [rbp-138h]
  UFG::qReflectField *v54; // [rsp+38h] [rbp-130h]
  unsigned __int64 v55; // [rsp+40h] [rbp-128h]
  UFG::qReflectType *v56; // [rsp+48h] [rbp-120h]
  UFG::qString result; // [rsp+50h] [rbp-118h]
  __int64 v58; // [rsp+78h] [rbp-F0h]
  UFG::qString v59; // [rsp+80h] [rbp-E8h]
  UFG::qString v60; // [rsp+A8h] [rbp-C0h]
  UFG::qString v61; // [rsp+D0h] [rbp-98h]
  UFG::qString v62; // [rsp+F8h] [rbp-70h]
  unsigned int v63; // [rsp+170h] [rbp+8h]
  UFG::qReflectField *fielda; // [rsp+178h] [rbp+10h]
  UFG::qReflectType *type; // [rsp+180h] [rbp+18h]
  const char *v66; // [rsp+188h] [rbp+20h]

  v66 = field_data;
  type = field_type;
  fielda = field;
  v58 = -2i64;
  v4 = field_type;
  v5 = field;
  v6 = this;
  v7 = &this->mArrayIndices;
  v8 = this->mArrayIndices.size;
  v9 = v8 + 1;
  v10 = this->mArrayIndices.capacity;
  if ( (signed int)v8 + 1 > v10 )
  {
    if ( v10 )
      v11 = 2 * v10;
    else
      v11 = 1;
    for ( ; v11 < v9; v11 *= 2 )
      ;
    if ( v11 <= 4 )
      v11 = 4;
    if ( v11 - v9 > 0x10000 )
      v11 = v8 + 65537;
    UFG::qArray<long,0>::Reallocate(v7, v11, "qArray.Add");
  }
  v7->size = v9;
  v7->p[v8] = 0;
  DNA::DUIReflectWidget::GetDisplayName(v6, &result, v6->mFieldStack.p[v6->mFieldStack.size - 2]);
  UFG::DUIContext::BeginIndent(v6->mContext);
  v12 = (UFG::qReflectField *)v4->mOrderedFields.mNode.mNext;
  v54 = v12;
  v13 = UFG::ReflectionDB::Instance();
  v14 = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v13, v12->mTypeName);
  v56 = v14;
  v15 = 0i64;
  v55 = 0i64;
  if ( v5->mArrayLength )
  {
    v16 = type;
    do
    {
      v7->p[v7->size - 1] = v15;
      v17 = &v66[v15 * v16->mNumBytes];
      v53 = v17;
      v18 = *((_DWORD *)v17 + 2);
      v63 = v18;
      if ( v18 )
      {
        v19 = v14->mFlags;
        if ( v19 & 0x10 )
        {
          v20 = 0;
          if ( v18 )
          {
            v21 = 0i64;
            do
            {
              v22 = v7->size;
              v23 = v22 + 1;
              v24 = v7->capacity;
              if ( (signed int)v22 + 1 > v24 )
              {
                if ( v24 )
                  v25 = 2 * v24;
                else
                  v25 = 1;
                for ( ; v25 < v23; v25 *= 2 )
                  ;
                if ( v25 <= 4 )
                  v25 = 4;
                if ( v25 - v23 > 0x10000 )
                  v25 = v22 + 65537;
                if ( v25 != (_DWORD)v22 )
                {
                  v26 = 4i64 * v25;
                  if ( !is_mul_ok(v25, 4ui64) )
                    v26 = -1i64;
                  v27 = UFG::qMalloc(v26, "qArray.Add", 0i64);
                  v28 = (unsigned int *)v27;
                  if ( v7->p )
                  {
                    v29 = 0i64;
                    if ( v7->size )
                    {
                      do
                      {
                        *((_DWORD *)&v27->mNext + v29) = v7->p[v29];
                        v29 = (unsigned int)(v29 + 1);
                      }
                      while ( (unsigned int)v29 < v7->size );
                    }
                    operator delete[](v7->p);
                  }
                  v7->p = v28;
                  v7->capacity = v25;
                  v17 = v53;
                  v5 = fielda;
                  v16 = type;
                }
              }
              v7->size = v23;
              v7->p[v22] = v20;
              if ( v54->mFlags & 0x4000 )
              {
                v30 = *(_QWORD *)(v21 + *(_QWORD *)v17);
                v31 = DNA::DUIReflectWidget::GetSubObject(v6, v16, v5);
                v32 = *(_QWORD *)(v30 + 56);
                v33 = UFG::ReflectionDB::Instance();
                v34 = UFG::ReflectionDB::GetType(v33, v32);
                UFG::qString::FormatEx(&v61, "%s[%d] [%s]", result.mData, v20, v34->mTree.mCount);
                v35 = DNA::DUIReflectWidget::GetExpandedState(v6, type, v5);
                if ( (unsigned __int8)UFG::DUIContext::Collapsible(v6->mContext, v61.mData, v35) )
                {
                  UFG::DUIContext::BeginIndent(v6->mContext);
                  DNA::DUIReflectWidget::UpdateUI(v31->mWidget, v6->mContext);
                  UFG::DUIContext::EndIndent(v6->mContext);
                }
                v36 = &v61;
              }
              else
              {
                v37 = DNA::DUIReflectWidget::GetSubObject(v6, v16, v5);
                UFG::qString::FormatEx(&v59, "%s[%d]", result.mData, v20);
                v38 = DNA::DUIReflectWidget::GetExpandedState(v6, type, v5);
                if ( (unsigned __int8)UFG::DUIContext::Collapsible(v6->mContext, v59.mData, v38) )
                {
                  UFG::DUIContext::BeginIndent(v6->mContext);
                  DNA::DUIReflectWidget::UpdateUI(v37->mWidget, v6->mContext);
                  UFG::DUIContext::EndIndent(v6->mContext);
                }
                v36 = &v59;
              }
              UFG::qString::~qString(v36);
              if ( v7->size > 1 )
                --v7->size;
              else
                v7->size = 0;
              ++v20;
              v21 += 8i64;
              v17 = v53;
              v16 = type;
            }
            while ( v20 < v63 );
            v14 = v56;
          }
LABEL_77:
          v12 = v54;
          goto LABEL_78;
        }
        if ( v19 & 1 || v19 & 8 || (v19 & 0x80u) != 0 )
        {
          v49 = 0;
          if ( v18 )
          {
            v50 = 0i64;
            do
            {
              v51 = (const char *)(*(_QWORD *)v17
                                 + (~(v14->mAlignment - 1i64) & (v14->mAlignment + v50 * v14->mNumBytes - 1)));
              UFG::DUIContext::BeginGridLayout(v6->mContext, 2, 1, 4);
              UFG::DUIContext::BeginIndent(v6->mContext);
              UFG::qString::FormatEx(&v62, "%s[%d]", result.mData, v49);
              UFG::DUIContext::Label(v6->mContext, v62.mData);
              UFG::DUIContext::EndIndent(v6->mContext);
              DNA::DUIReflectWidget::AddBasicType(v6, v12, v14, v51);
              UFG::DUIContext::EndLayoutHorizontal(v6->mContext);
              UFG::qString::~qString(&v62);
              ++v49;
              ++v50;
              v17 = v53;
            }
            while ( v49 < v18 );
            v7 = &v6->mArrayIndices;
            v5 = fielda;
            v16 = type;
          }
          goto LABEL_78;
        }
        v39 = 0;
        if ( v18 )
        {
          v40 = 0i64;
          do
          {
            v41 = v7->size;
            v42 = v41 + 1;
            v43 = v7->capacity;
            if ( (signed int)v41 + 1 > v43 )
            {
              if ( v43 )
                v44 = 2 * v43;
              else
                v44 = 1;
              for ( ; v44 < v42; v44 *= 2 )
                ;
              if ( v44 <= 4 )
                v44 = 4;
              if ( v44 - v42 > 0x10000 )
                v44 = v41 + 65537;
              UFG::qArray<long,0>::Reallocate(v7, v44, "qArray.Add");
            }
            v7->size = v42;
            v7->p[v41] = v39;
            v45 = (UFG::qColour *)(*(_QWORD *)v53
                                 + (~(v14->mAlignment - 1i64) & (v14->mAlignment + v40 * v14->mNumBytes - 1)));
            UFG::qString::FormatEx(&v60, "%s[%d]", result.mData, v39);
            v5 = fielda;
            v46 = DNA::DUIReflectWidget::GetExpandedState(v6, type, fielda);
            if ( (unsigned __int8)UFG::DUIContext::Collapsible(v6->mContext, v60.mData, v46) )
            {
              v47 = DNA::HasEditor(v14, "ColourPicker");
              v48 = v6->mContext;
              if ( v47 )
              {
                UFG::DUIContext::ColourPicker(v48, &customWorldMapCaption, v45, 1);
              }
              else
              {
                UFG::DUIContext::BeginIndent(v48);
                UFG::qReflectVisitor::VisitObject((UFG::qReflectVisitor *)&v6->vfptr, v14, (const char *)v45);
                UFG::DUIContext::EndIndent(v6->mContext);
              }
            }
            if ( v7->size > 1 )
              --v7->size;
            else
              v7->size = 0;
            UFG::qString::~qString(&v60);
            ++v39;
            ++v40;
          }
          while ( v39 < v18 );
          v16 = type;
          goto LABEL_77;
        }
      }
LABEL_78:
      v15 = v55 + 1;
      v55 = v15;
    }
    while ( v15 < v5->mArrayLength );
  }
  UFG::DUIContext::EndIndent(v6->mContext);
  if ( v7->size > 1 )
    --v7->size;
  else
    v7->size = 0;
  UFG::qString::~qString(&result);
  return 0;
}

// File Line: 939
// RVA: 0x1B3270
void __fastcall DNA::DUIReflectWidget::BeginBytes(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *data)
{
  UFG::qReflectType *v4; // r13
  UFG::qReflectField *v5; // r15
  DNA::DUIReflectWidget *v6; // rsi
  int v7; // ebx
  unsigned __int64 v8; // r14
  unsigned __int64 v9; // r12
  char *v10; // rdi
  bool *v11; // rax
  unsigned int v12; // ebp
  __int64 v13; // rdi
  UFG::qColour *v14; // rdi
  char v15; // al
  UFG::DUIContext *v16; // rcx
  UFG::qString *v17; // rax
  __int64 v18; // [rsp+20h] [rbp-D8h]
  UFG::qString result; // [rsp+28h] [rbp-D0h]
  __int64 v20; // [rsp+50h] [rbp-A8h]
  UFG::qString v21; // [rsp+58h] [rbp-A0h]
  UFG::qString v22; // [rsp+80h] [rbp-78h]
  UFG::qString v23; // [rsp+A8h] [rbp-50h]
  const char *v24; // [rsp+118h] [rbp+20h]

  v24 = data;
  v20 = -2i64;
  v4 = field_type;
  v5 = field;
  v6 = this;
  v7 = 0;
  LODWORD(v18) = 0;
  if ( !DNA::IsHidden(this->mTypeStack.p[this->mTypeStack.size - 1], field) )
  {
    v8 = v5->mArrayLength;
    v9 = v4->mNumBytes;
    DNA::DUIReflectWidget::GetDisplayName(v6, &result, v5);
    if ( v8 <= 1
      || (v10 = result.mData,
          v11 = DNA::DUIReflectWidget::GetExpandedState(v6, v4, v5),
          (unsigned __int8)UFG::DUIContext::Collapsible(v6->mContext, v10, v11)) )
    {
      v12 = 0;
      if ( v8 )
      {
        v13 = 0i64;
        do
        {
          v14 = (UFG::qColour *)&v24[v9 * v13];
          v15 = DNA::HasEditor(v5, "ColourPicker");
          v16 = v6->mContext;
          if ( v15 )
          {
            UFG::DUIContext::ColourPicker(v16, &customWorldMapCaption, v14, 1);
          }
          else
          {
            UFG::DUIContext::BeginGridLayout(v16, 2, 1, 4);
            UFG::DUIContext::BeginIndent(v6->mContext);
            if ( v8 <= 1 )
            {
              UFG::qString::qString(&v22, &result);
              v7 |= 2u;
            }
            else
            {
              v17 = UFG::qString::FormatEx(&v23, "%s[%d]", result.mData, v12, v18);
              v7 |= 1u;
            }
            LODWORD(v18) = v7;
            UFG::qString::qString(&v21, v17);
            if ( v7 & 2 )
            {
              v7 &= 0xFFFFFFFD;
              LODWORD(v18) = v7;
              UFG::qString::~qString(&v22);
            }
            if ( v7 & 1 )
            {
              v7 &= 0xFFFFFFFE;
              LODWORD(v18) = v7;
              UFG::qString::~qString(&v23);
            }
            UFG::DUIContext::Label(v6->mContext, v21.mData);
            UFG::DUIContext::EndIndent(v6->mContext);
            DNA::DUIReflectWidget::AddBasicType(v6, v5, v4, (const char *)v14);
            UFG::DUIContext::EndLayoutHorizontal(v6->mContext);
            UFG::qString::~qString(&v21);
          }
          v13 = ++v12;
        }
        while ( v12 < v8 );
      }
    }
    UFG::qString::~qString(&result);
  }
}

// File Line: 982
// RVA: 0x1B5AF0
void __fastcall DNA::DUIReflectWidget::UpdateUI(DNA::DUIReflectWidget *this, UFG::DUIContext *dui)
{
  bool v2; // zf
  DNA::DUIReflectWidget *v3; // rdi
  __int64 v4; // rsi
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned int *v8; // rax
  unsigned __int64 v9; // rbx
  UFG::ReflectionDB *v10; // rax
  UFG::qReflectType *v11; // rax
  unsigned int v12; // eax

  v2 = this->mObject == 0i64;
  v3 = this;
  this->mContext = dui;
  if ( v2 )
  {
    this->mContext = 0i64;
  }
  else
  {
    v4 = this->mArrayIndices.size;
    v5 = this->mArrayIndices.capacity;
    v6 = v4 + 1;
    if ( (signed int)v4 + 1 > v5 )
    {
      if ( v5 )
        v7 = 2 * v5;
      else
        v7 = 1;
      for ( ; v7 < v6; v7 *= 2 )
        ;
      if ( v7 <= 4 )
        v7 = 4;
      if ( v7 - v6 > 0x10000 )
        v7 = v4 + 65537;
      UFG::qArray<long,0>::Reallocate(&this->mArrayIndices, v7, "qArray.Add");
    }
    v8 = v3->mArrayIndices.p;
    v3->mArrayIndices.size = v6;
    v8[v4] = 0;
    v9 = v3->mObject->mTypeUID;
    v10 = UFG::ReflectionDB::Instance();
    v11 = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v10, v9);
    UFG::qReflectVisitor::TrackObject((UFG::qReflectVisitor *)&v3->vfptr, v11, (const char *)v3->mObject);
    UFG::qReflectVisitor::VisitObjects((UFG::qReflectVisitor *)&v3->vfptr);
    v3->mTrackedObjects.size = 0;
    v3->mPatches.size = 0;
    v3->mArrays.size = 0;
    v12 = v3->mArrayIndices.size;
    if ( v12 > 1 )
      v3->mArrayIndices.size = v12 - 1;
    else
      v3->mArrayIndices.size = 0;
    v3->mContext = 0i64;
  }
}

// File Line: 1003
// RVA: 0x1B3DD0
UFG::qString *__fastcall DNA::DUIReflectWidget::GetDisplayName(DNA::DUIReflectWidget *this, UFG::qString *result, UFG::qReflectField *field)
{
  UFG::qString *v3; // rbx

  v3 = result;
  DNA::GetDisplayName(result, this->mTypeStack.p[this->mTypeStack.size - 1], field);
  return v3;
}

// File Line: 1023
// RVA: 0x1B3F70
bool *__fastcall DNA::DUIReflectWidget::GetExpandedState(DNA::DUIReflectWidget *this, UFG::qReflectType *type, UFG::qReflectField *field)
{
  UFG::qReflectField *v3; // rsi
  UFG::qReflectType *v4; // rbp
  DNA::DUIReflectWidget *v5; // rbx
  unsigned __int64 v6; // rax
  __int64 v7; // rdi
  UFG::qArray<DNA::DUIReflectWidget::ExpandState,0> *v8; // r15
  unsigned int v9; // er9
  unsigned __int64 v10; // r14
  DNA::DUIReflectWidget::ExpandState *v11; // rax
  unsigned int v12; // edx
  unsigned int v13; // ebx
  unsigned int v14; // edx
  bool *result; // rax
  signed __int64 v16; // rcx

  v3 = field;
  v4 = type;
  v5 = this;
  v6 = DNA::DUIReflectWidget::GetIDForObject(this);
  v7 = v5->mExpandState.size;
  v8 = &v5->mExpandState;
  v9 = 0;
  v10 = v6;
  if ( (_DWORD)v7 )
  {
    v11 = v5->mExpandState.p;
    while ( v11->mField != v3 || v11->mType != v4 || v11->mId != v10 )
    {
      ++v9;
      ++v11;
      if ( v9 >= (unsigned int)v7 )
        goto LABEL_7;
    }
    result = &v11->mExpanded;
  }
  else
  {
LABEL_7:
    v12 = v5->mExpandState.capacity;
    v13 = v7 + 1;
    if ( (signed int)v7 + 1 > v12 )
    {
      if ( v12 )
        v14 = 2 * v12;
      else
        v14 = 1;
      for ( ; v14 < v13; v14 *= 2 )
        ;
      if ( v14 - v13 > 0x10000 )
        v14 = v7 + 65537;
      UFG::qArray<DNA::DUIReflectWidget::ExpandState,0>::Reallocate(v8, v14, "qArray.Add");
    }
    v8->size = v13;
    v16 = (signed __int64)&v8->p[v7];
    *(_BYTE *)(v16 + 24) = 0;
    result = (bool *)(v16 + 24);
    *(_QWORD *)(v16 + 8) = v3;
    *(_QWORD *)v16 = v4;
    *(_QWORD *)(v16 + 16) = v10;
  }
  return result;
}

// File Line: 1043
// RVA: 0x1B4110
DNA::DUIReflectWidget::SubObject *__fastcall DNA::DUIReflectWidget::GetSubObject(DNA::DUIReflectWidget *this, UFG::qReflectType *type, UFG::qReflectField *field)
{
  UFG::qReflectField *v3; // r14
  UFG::qReflectType *v4; // r15
  DNA::DUIReflectWidget *v5; // rbx
  unsigned __int64 v6; // rbp
  DNA::DUIReflectWidget::SubObject *result; // rax
  DNA::DUIReflectWidget::SubObject *v8; // rsi
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rbx
  UFG::allocator::free_link *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *v14; // rcx

  v3 = field;
  v4 = type;
  v5 = this;
  v6 = DNA::DUIReflectWidget::GetIDForObject(this);
  result = (DNA::DUIReflectWidget::SubObject *)v5->mSubObjects.mNode.mNext;
  v8 = (DNA::DUIReflectWidget::SubObject *)&v5->mSubObjects;
  while ( result != v8 )
  {
    if ( result->mField == v3 && result->mType == v4 && result->mId == v6 )
      return result;
    result = (DNA::DUIReflectWidget::SubObject *)result->mNext;
  }
  v9 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v10 = v9;
  if ( v9 )
  {
    v9->mNext = v9;
    v9[1].mNext = v9;
    v11 = 0i64;
    v9[2].mNext = 0i64;
    v9[3].mNext = 0i64;
    v9[4].mNext = 0i64;
    v9[5].mNext = 0i64;
  }
  else
  {
    v11 = 0i64;
    v10 = 0i64;
  }
  v10[3].mNext = (UFG::allocator::free_link *)v3;
  v10[2].mNext = (UFG::allocator::free_link *)v4;
  v12 = UFG::qMalloc(0xC8ui64, UFG::gGlobalNewName, 0i64);
  if ( v12 )
  {
    DNA::DUIReflectWidget::DUIReflectWidget((DNA::DUIReflectWidget *)v12);
    v11 = v13;
  }
  v10[5].mNext = v11;
  v10[4].mNext = (UFG::allocator::free_link *)v6;
  v14 = v8->mPrev;
  v14->mNext = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v10;
  v10->mNext = (UFG::allocator::free_link *)v14;
  v10[1].mNext = (UFG::allocator::free_link *)v8;
  v8->mPrev = (UFG::qNode<DNA::DUIReflectWidget::SubObject,DNA::DUIReflectWidget::SubObject> *)v10;
  return (DNA::DUIReflectWidget::SubObject *)v10;
}

// File Line: 1063
// RVA: 0x1B4050
unsigned __int64 __fastcall DNA::DUIReflectWidget::GetIDForObject(DNA::DUIReflectWidget *this)
{
  __int64 v1; // rbp
  DNA::DUIReflectWidget *v2; // rbx
  unsigned __int64 v3; // rdi
  unsigned int v4; // esi
  unsigned __int64 v5; // rax
  unsigned __int64 result; // rax
  char dest; // [rsp+20h] [rbp-108h]

  v1 = 0i64;
  v2 = this;
  v3 = this->mObject->mBaseNode.mUID;
  v4 = 0;
  if ( this->mFieldStack.size )
  {
    do
    {
      v5 = UFG::qStringHash64(v2->mFieldStack.p[v4++]->mName, v3);
      v3 = v5;
    }
    while ( v4 < v2->mFieldStack.size );
  }
  if ( v2->mArrayIndices.size <= 0 )
    return v3;
  do
  {
    UFG::qSPrintf(&dest, 256, "{%d}", v2->mArrayIndices.p[v1]);
    result = UFG::qStringHash64(&dest, v3);
    v1 = (unsigned int)(v1 + 1);
    v3 = result;
  }
  while ( (unsigned int)v1 < v2->mArrayIndices.size );
  return result;
}

// File Line: 1085
// RVA: 0x1B1DC0
void __fastcall DNA::DUIReflectWidget::AddBasicType(DNA::DUIReflectWidget *this, UFG::qReflectField *field, UFG::qReflectType *field_type, const char *element_data)
{
  unsigned int *v4; // rdi
  UFG::qReflectType *v5; // r14
  UFG::qReflectField *v6; // rsi
  DNA::DUIReflectWidget *v7; // rbx
  unsigned int v8; // eax
  unsigned __int64 v9; // rax
  __int64 v10; // rax
  UFG::ReflectionDB *v11; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v12; // rax
  int v13; // er15
  UFG::qTree64Base::BaseNode *v14; // rsi
  signed __int64 i; // r12
  UFG::qString *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rax
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v23; // rdx
  unsigned __int64 v24; // rax
  UFG::qString *j; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rcx
  char *v29; // rdx
  unsigned int v30; // eax
  char *v31; // rax
  UFG::qSymbol *v32; // rax
  const char *v33; // rax
  UFG::qWiseSymbol *v34; // rax
  char *v35; // rax
  unsigned __int64 v36; // rax
  UFG::qString *v37; // rax
  unsigned int v38; // esi
  UFG::qString *v39; // rax
  unsigned int v40; // esi
  UFG::qString *v41; // rax
  unsigned int v42; // esi
  UFG::qString *v43; // rax
  unsigned int v44; // esi
  unsigned int v45; // eax
  UFG::qString *v46; // rax
  unsigned int v47; // esi
  UFG::qString *v48; // [rsp+8h] [rbp-79h]
  UFG::qString string_data; // [rsp+10h] [rbp-71h]
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+38h] [rbp-49h]
  UFG::qString result; // [rsp+60h] [rbp-21h]
  __int64 v52; // [rsp+88h] [rbp+7h]
  int current_index; // [rsp+E8h] [rbp+67h]
  __int64 value_to_write; // [rsp+F8h] [rbp+77h]
  UFG::qString *v55; // [rsp+100h] [rbp+7Fh]

  v52 = -2i64;
  v4 = (unsigned int *)element_data;
  v5 = field_type;
  v6 = field;
  v7 = this;
  string_data.mStringHash32 = 0;
  v8 = field_type->mFlags;
  if ( v8 & 4 )
  {
    value_to_write = 0i64;
    v9 = field_type->mNumBytes;
    if ( v9 == 4 )
    {
      v10 = *(signed int *)element_data;
    }
    else
    {
      if ( v9 != 8 )
      {
LABEL_7:
        UFG::qString::qString(&string_data);
        if ( !DNA::FindEnumStringFromValue(v5->mName, &value_to_write, &string_data) )
          UFG::qPrintf(
            "Warning: AddBasicType() could not find enum value for field %s of type %s.  Replacing with an empty string.\n",
            v6->mName,
            v5->mName);
        current_index = 0;
        options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
        v11 = UFG::ReflectionDB::Instance();
        v12 = UFG::ReflectionDB::GetEnum(v11, v5->mName);
        if ( v12 )
        {
          v13 = 0;
          v14 = v12[1].mTree.mHead.mChildren[0];
          for ( i = (signed __int64)&v12[1].mTree.mHead.mParent; v14 != (UFG::qTree64Base::BaseNode *)i; v14 = v14->mParent )
          {
            v16 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
            v55 = v16;
            if ( v16 )
            {
              UFG::qString::qString(v16, (const char *)v14->mChildren[0]);
              v18 = v17;
            }
            else
            {
              v18 = 0i64;
            }
            v19 = options.mNode.mPrev;
            options.mNode.mPrev->mNext = v18;
            v18->mPrev = v19;
            v18->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
            options.mNode.mPrev = v18;
            v20 = UFG::qStringCompare((const char *)v14->mChildren[0], string_data.mData, -1);
            v21 = current_index;
            if ( !v20 )
              v21 = v13;
            current_index = v21;
            ++v13;
          }
        }
        string_data.mMagic = -1;
        if ( UFG::DUIContext::ComboBox(v7->mContext, &current_index, &options, 0i64, 0xFFFFFFFF) )
        {
          v22 = 0;
          v23 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v48;
          if ( v48 != (UFG::qString *)&options )
          {
            while ( v22 != current_index )
            {
              ++v22;
              v23 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v23->mNode.mNext;
              if ( v23 == &options )
                goto LABEL_27;
            }
            if ( DNA::FindEnumValueFromString(v5->mName, (UFG::qString *)v23, &value_to_write) )
            {
              v24 = v5->mNumBytes;
              if ( v24 == 4 )
              {
                *v4 = value_to_write;
              }
              else if ( v24 == 8 )
              {
                *(_QWORD *)v4 = value_to_write;
              }
            }
          }
        }
LABEL_27:
        for ( j = v48; v48 != (UFG::qString *)&options; j = v48 )
        {
          v26 = j->mPrev;
          v27 = j->mNext;
          v26->mNext = v27;
          v27->mPrev = v26;
          j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
          j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
          UFG::qString::~qString(j);
          operator delete[](j);
        }
        v28 = options.mNode.mPrev;
        options.mNode.mPrev->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v48->mPrev;
        v48->mPrev = v28;
        options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
        goto LABEL_118;
      }
      v10 = *(_QWORD *)element_data;
    }
    value_to_write = v10;
    goto LABEL_7;
  }
  if ( v8 & 8 )
  {
    if ( this->mActiveEdit == element_data )
    {
      v29 = this->mEditValue.mData;
    }
    else if ( *((_DWORD *)element_data + 2) <= 0u )
    {
      v29 = &customWorldMapCaption;
    }
    else
    {
      v29 = *(char **)element_data;
    }
    UFG::qString::qString(&string_data, v29);
    LODWORD(string_data.mData) = -1;
    *(_QWORD *)&string_data.mMagic = 0i64;
    if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &string_data, 0i64, 1, 0i64, 0xFFFFFFFF) )
    {
      v7->mActiveEdit = (const char *)v4;
      UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      UFG::qReflectString::Set((UFG::qReflectString *)v4, string_data.mData);
    }
    goto LABEL_118;
  }
  if ( (v8 & 0x80u) != 0 )
  {
    UFG::qString::qString(&string_data);
    v30 = v5->mFlags;
    if ( _bittest((const signed int *)&v30, 8u) )
    {
      if ( (unsigned int *)v7->mActiveEdit == v4 )
        v31 = v7->mEditValue.mData;
      else
        v31 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v4);
      UFG::qString::Set(&string_data, v31);
      LODWORD(string_data.mData) = -1;
      *(_QWORD *)&string_data.mMagic = 0i64;
      if ( !(unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &string_data, 0i64, 1, 0i64, 0xFFFFFFFF) )
        goto LABEL_118;
      v7->mActiveEdit = (const char *)v4;
      UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      v32 = (UFG::qSymbol *)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&current_index, v7->mEditValue.mData);
    }
    else
    {
      if ( _bittest((const signed int *)&v30, 9u) )
      {
        if ( (unsigned int *)v7->mActiveEdit == v4 )
          v33 = v7->mEditValue.mData;
        else
          v33 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)v4);
        UFG::qString::Set(&string_data, v33);
        LODWORD(string_data.mData) = -1;
        *(_QWORD *)&string_data.mMagic = 0i64;
        if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &string_data, 0i64, 1, 0i64, 0xFFFFFFFF) )
        {
          v7->mActiveEdit = (const char *)v4;
          UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
          v34 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&current_index, v7->mEditValue.mData);
          UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)v4, v34);
          _((AMD_HD3D *)(unsigned int)current_index);
        }
        goto LABEL_118;
      }
      if ( (unsigned int *)v7->mActiveEdit == v4 )
        v35 = v7->mEditValue.mData;
      else
        v35 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v4);
      UFG::qString::Set(&string_data, v35);
      LODWORD(string_data.mData) = -1;
      *(_QWORD *)&string_data.mMagic = 0i64;
      if ( !(unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &string_data, 0i64, 1, 0i64, 0xFFFFFFFF) )
        goto LABEL_118;
      v7->mActiveEdit = (const char *)v4;
      UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      v32 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&current_index, v7->mEditValue.mData);
    }
    *v4 = v32->mUID;
    goto LABEL_118;
  }
  UFG::qString::qString(&string_data);
  v36 = v5->mNameUID;
  if ( v36 == DNA::kBasicTypeUID_long_long )
  {
    if ( (unsigned int *)v7->mActiveEdit == v4 )
    {
      UFG::qString::qString(&result, &v7->mEditValue);
      v38 = 1;
    }
    else
    {
      v37 = UFG::qString::FormatEx((UFG::qString *)&options, "%d", *(_QWORD *)v4);
      v38 = 2;
    }
    string_data.mStringHash32 = v38;
    UFG::qString::Set(&string_data, v37->mData, v37->mLength, 0i64, 0);
    if ( v38 & 2 )
    {
      v38 &= 0xFFFFFFFD;
      string_data.mStringHash32 = v38;
      UFG::qString::~qString((UFG::qString *)&options);
    }
    if ( v38 & 1 )
    {
      string_data.mStringHash32 = v38 & 0xFFFFFFFE;
      UFG::qString::~qString(&result);
    }
    LODWORD(string_data.mData) = -1;
    *(_QWORD *)&string_data.mMagic = 0i64;
    if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &string_data, 0i64, 1, 0i64, 0xFFFFFFFF) )
    {
      v7->mActiveEdit = (const char *)v4;
      UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      *(_QWORD *)v4 = UFG::qToInt64(v7->mEditValue.mData, *(_QWORD *)v4);
    }
    goto LABEL_118;
  }
  if ( v36 == DNA::kBasicTypeUID_long || v36 == DNA::kBasicTypeUID_int )
  {
    LODWORD(value_to_write) = 0;
    current_index = 0;
    if ( DNA::HasRange(v7->mTypeStack.p[v7->mTypeStack.size - 1], v6, (int *)&value_to_write, &current_index) )
    {
      *(float *)&string_data.mData = FLOAT_N1_0;
      string_data.mMagic = current_index;
      UFG::DUIContext::Slider(v7->mContext, &customWorldMapCaption, (int *)v4, value_to_write);
      goto LABEL_118;
    }
    if ( (unsigned int *)v7->mActiveEdit == v4 )
    {
      UFG::qString::qString((UFG::qString *)&options, &v7->mEditValue);
      v47 = 4;
    }
    else
    {
      v46 = UFG::qString::FormatEx(&result, "%d", *v4);
      v47 = 8;
    }
    string_data.mStringHash32 = v47;
    UFG::qString::Set(&string_data, v46->mData, v46->mLength, 0i64, 0);
    if ( v47 & 8 )
    {
      v47 &= 0xFFFFFFF7;
      string_data.mStringHash32 = v47;
      UFG::qString::~qString(&result);
    }
    if ( v47 & 4 )
    {
      string_data.mStringHash32 = v47 & 0xFFFFFFFB;
      UFG::qString::~qString((UFG::qString *)&options);
    }
    LODWORD(string_data.mData) = -1;
    *(_QWORD *)&string_data.mMagic = 0i64;
    if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &string_data, 0i64, 1, 0i64, 0xFFFFFFFF) )
    {
      v7->mActiveEdit = (const char *)v4;
      UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      v45 = UFG::qToInt32(v7->mEditValue.mData, *v4);
      goto LABEL_117;
    }
  }
  else
  {
    if ( v36 == DNA::kBasicTypeUID_unsigned_long_long )
    {
      if ( (unsigned int *)v7->mActiveEdit == v4 )
      {
        UFG::qString::qString((UFG::qString *)&options, &v7->mEditValue);
        v40 = 16;
      }
      else
      {
        v39 = UFG::qString::FormatEx(&result, "%d", *(_QWORD *)v4);
        v40 = 32;
      }
      string_data.mStringHash32 = v40;
      UFG::qString::Set(&string_data, v39->mData, v39->mLength, 0i64, 0);
      if ( v40 & 0x20 )
      {
        v40 &= 0xFFFFFFDF;
        string_data.mStringHash32 = v40;
        UFG::qString::~qString(&result);
      }
      if ( v40 & 0x10 )
      {
        string_data.mStringHash32 = v40 & 0xFFFFFFEF;
        UFG::qString::~qString((UFG::qString *)&options);
      }
      LODWORD(string_data.mData) = -1;
      *(_QWORD *)&string_data.mMagic = 0i64;
      if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &string_data, 0i64, 1, 0i64, 0xFFFFFFFF) )
      {
        v7->mActiveEdit = (const char *)v4;
        UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
        *(_QWORD *)v4 = UFG::qToUInt64(v7->mEditValue.mData, *(_QWORD *)v4);
      }
      goto LABEL_118;
    }
    if ( v36 != DNA::kBasicTypeUID_unsigned_long && v36 != DNA::kBasicTypeUID_unsigned_int )
    {
      if ( v36 == DNA::kBasicTypeUID_float )
      {
        LODWORD(value_to_write) = 0;
        current_index = 0;
        if ( DNA::HasRange(
               v7->mTypeStack.p[v7->mTypeStack.size - 1],
               v6,
               (float *)&value_to_write,
               (float *)&current_index) )
        {
          LODWORD(string_data.mData) = 0;
          string_data.mMagic = current_index;
          UFG::DUIContext::Slider(v7->mContext, &customWorldMapCaption, (float *)v4, *(float *)&value_to_write);
        }
        else
        {
          if ( (unsigned int *)v7->mActiveEdit == v4 )
          {
            UFG::qString::qString((UFG::qString *)&options, &v7->mEditValue);
            v42 = 256;
          }
          else
          {
            v41 = UFG::qString::FormatEx(&result, "%f", *(float *)v4);
            v42 = 512;
          }
          string_data.mStringHash32 = v42;
          UFG::qString::Set(&string_data, v41->mData, v41->mLength, 0i64, 0);
          if ( _bittest((const signed int *)&v42, 9u) )
          {
            v42 &= 0xFFFFFDFF;
            string_data.mStringHash32 = v42;
            UFG::qString::~qString(&result);
          }
          if ( _bittest((const signed int *)&v42, 8u) )
          {
            string_data.mStringHash32 = v42 & 0xFFFFFEFF;
            UFG::qString::~qString((UFG::qString *)&options);
          }
          LODWORD(string_data.mData) = -1;
          *(_QWORD *)&string_data.mMagic = 0i64;
          if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &string_data, 0i64, 1, 0i64, 0xFFFFFFFF) )
          {
            v7->mActiveEdit = (const char *)v4;
            UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
            *(float *)v4 = UFG::qToFloat(v7->mEditValue.mData, *(float *)v4);
          }
        }
      }
      else if ( v36 == DNA::kBasicTypeUID_bool )
      {
        UFG::DUIContext::Checkbox(v7->mContext, &customWorldMapCaption, (bool *)v4);
      }
      goto LABEL_118;
    }
    if ( (unsigned int *)v7->mActiveEdit == v4 )
    {
      UFG::qString::qString((UFG::qString *)&options, &v7->mEditValue);
      v44 = 64;
    }
    else
    {
      v43 = UFG::qString::FormatEx(&result, "%d", *v4);
      v44 = 128;
    }
    string_data.mStringHash32 = v44;
    UFG::qString::Set(&string_data, v43->mData, v43->mLength, 0i64, 0);
    if ( (v44 & 0x80u) != 0 )
    {
      v44 &= 0xFFFFFF7F;
      string_data.mStringHash32 = v44;
      UFG::qString::~qString(&result);
    }
    if ( v44 & 0x40 )
    {
      string_data.mStringHash32 = v44 & 0xFFFFFFBF;
      UFG::qString::~qString((UFG::qString *)&options);
    }
    LODWORD(string_data.mData) = -1;
    *(_QWORD *)&string_data.mMagic = 0i64;
    if ( (unsigned __int8)UFG::DUIContext::TextBox(v7->mContext, &string_data, 0i64, 1, 0i64, 0xFFFFFFFF) )
    {
      v7->mActiveEdit = (const char *)v4;
      UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      v45 = UFG::qToUInt32(v7->mEditValue.mData, *v4);
LABEL_117:
      *v4 = v45;
      goto LABEL_118;
    }
  }
LABEL_118:
  UFG::qString::~qString(&string_data);
  if ( (unsigned int *)v7->mActiveEdit == v4 && v7->mContext->mCurrentID != v7->mContext->mFocusedID )
    v7->mActiveEdit = 0i64;
}FFFFFF) )
    {
      v7->mActiveEdit = (const char *)v4;
      UFG::qString::Set(&v7->mEditValue, string_data.mData, string_data.mLength, 0i64, 0);
      v45 = UFG::qToUInt32(v7->mEditValue.mData, *v4);
LABEL_117:
      *v4 = v45;
      goto LABEL_118;
   

// File Line: 1301
// RVA: 0x1B5170
void __fastcall DNA::DUIReflectInspector::OnPropertyChanged(char *object, UFG::qReflectField *field, UFG::qReflectType *field_type, char *field_data, void *user_data)
{
  UFG::qReflectType *v5; // rbx
  UFG::qReflectField *v6; // rdi
  char *v7; // rax

  v5 = field_type;
  v6 = field;
  v7 = UFG::qReflectObject::GetName((UFG::qReflectObject *)object);
  UFG::qPrintf("Property Changed on Object %s, Field %s, Type %s\n", v7, v6->mName, v5->mName, user_data);
}

// File Line: 1307
// RVA: 0x1B5150
void __fastcall DNA::DUIReflectInspector::OnObjectReloaded(char *object, void *user_data)
{
  if ( *((_QWORD *)user_data + 49) == *((_QWORD *)object + 1) )
    *((_QWORD *)user_data + 59) = object;
}

// File Line: 1329
// RVA: 0x1B5A90
void __fastcall DNA::DUIReflectInspector::UpdateUI(DNA::DUIReflectInspector *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  DNA::DUIReflectInspector *v3; // rbx

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginScrollView(dui, &this->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(v2);
  v3->mWidget.mObject = v3->mObjectHandle.mData;
  DNA::DUIReflectWidget::UpdateUI(&v3->mWidget, v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndScrollView(v2);
}

