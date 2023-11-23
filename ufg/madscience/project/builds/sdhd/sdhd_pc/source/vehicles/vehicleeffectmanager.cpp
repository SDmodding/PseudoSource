// File Line: 22
// RVA: 0x1582B50
__int64 dynamic_initializer_for__gBoundEffectSpeed__()
{
  UFG::qString::qString(gBoundEffectSpeed, "Speed0");
  UFG::qString::qString(&stru_142434AE8, "Speed1");
  UFG::qString::qString(&stru_142434B10, "Speed2");
  UFG::qString::qString(&stru_142434B38, "Speed3");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gBoundEffectSpeed__);
}

// File Line: 25
// RVA: 0x157B9F0
__int64 dynamic_initializer_for__EngineBlown_SYMBOL__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("EngineBlown", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&EngineBlown_SYMBOL, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__EngineBlown_SYMBOL__);
}

// File Line: 26
// RVA: 0x157B9B0
__int64 dynamic_initializer_for__Destroyed_SYMBOL__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Destroyed", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Destroyed_SYMBOL, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Destroyed_SYMBOL__);
}

// File Line: 52
// RVA: 0x6747E0
void UFG::VehicleEffectManager::Create(void)
{
  UFG::qBaseTreeRB *v0; // rax
  UFG::VehicleEffectManager *v1; // rbx

  v0 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x90ui64, "VehicleEffectManager", 0x800ui64);
  v1 = (UFG::VehicleEffectManager *)v0;
  if ( v0 )
  {
    UFG::qBaseTreeRB::qBaseTreeRB(v0);
    UFG::qBaseTreeRB::qBaseTreeRB(&v1->mVehicleEffectTemplates.mTree);
    UFG::VehicleEffectManager::m_Instance = v1;
  }
  else
  {
    UFG::VehicleEffectManager::m_Instance = 0i64;
  }
}

// File Line: 70
// RVA: 0x66F4F0
void __fastcall UFG::VehicleEffectManager::AddDamageTransferNode(
        UFG::VehicleEffectManager *this,
        SimpleXML::XMLDocument *doc,
        SimpleXML::XMLNode *node)
{
  char *Attribute; // rdi
  double v6; // xmm0_8
  float v7; // xmm8_4
  UFG::allocator::free_link *v8; // rsi
  int v9; // eax
  SimpleXML::XMLNode *ChildNode; // r12
  char *v11; // rbx
  float v12; // xmm6_4
  double v13; // xmm0_8
  UFG::allocator::free_link *v14; // r14
  int v15; // eax
  SimpleXML::XMLNode *v16; // rdi
  UFG::allocator::free_link *v17; // rsi
  char *v18; // r15
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rbx
  UFG::allocator::free_link *mNext; // rax
  UFG::qBaseTreeRB *v22; // [rsp+20h] [rbp-98h]
  UFG::qBaseNodeRB *x; // [rsp+D8h] [rbp+20h]

  Attribute = SimpleXML::XMLNode::GetAttribute(node, "name", &customCaption);
  v6 = SimpleXML::XMLNode::GetAttribute(node, "DefaultValue", COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
  v7 = *(float *)&v6;
  if ( SimpleXML::XMLNode::GetAttribute(node, "IsDefaultInfinite", 0) )
    v7 = FLOAT_N1_0;
  v8 = UFG::qMalloc(0x70ui64, "VehicleEffectManager", 0i64);
  x = (UFG::qBaseNodeRB *)v8;
  if ( v8 )
  {
    v9 = UFG::qStringHashUpper32(Attribute, -1);
    v8->mNext = 0i64;
    v8[1].mNext = 0i64;
    v8[2].mNext = 0i64;
    LODWORD(v8[3].mNext) = v9;
    UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&v8[4]);
    *(float *)&v8[13].mNext = v7;
  }
  else
  {
    v8 = 0i64;
    x = 0i64;
  }
  ChildNode = SimpleXML::XMLDocument::GetChildNode(doc, "DamageAffector", node);
  if ( ChildNode )
  {
    v22 = (UFG::qBaseTreeRB *)&v8[4];
    do
    {
      v11 = SimpleXML::XMLNode::GetAttribute(ChildNode, "name", &customCaption);
      v12 = v7;
      if ( !SimpleXML::XMLNode::GetAttribute(ChildNode, "UseDefault", 1) )
      {
        v13 = SimpleXML::XMLNode::GetAttribute(
                ChildNode,
                "Health",
                COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
        v12 = *(float *)&v13;
        if ( SimpleXML::XMLNode::GetAttribute(ChildNode, "Invincible", 0) )
          v12 = FLOAT_N1_0;
      }
      v14 = UFG::qMalloc(0x38ui64, "VehicleEffectManager", 0i64);
      if ( v14 )
      {
        v15 = UFG::qStringHashUpper32(v11, -1);
        v14->mNext = 0i64;
        v14[1].mNext = 0i64;
        v14[2].mNext = 0i64;
        LODWORD(v14[3].mNext) = v15;
        v14[4].mNext = v14 + 4;
        v14[5].mNext = v14 + 4;
        *(float *)&v14[6].mNext = v12;
      }
      else
      {
        v14 = 0i64;
      }
      v16 = SimpleXML::XMLDocument::GetChildNode(doc, "TransferTo", ChildNode);
      if ( v16 )
      {
        v17 = v14 + 4;
        do
        {
          v18 = SimpleXML::XMLNode::GetAttribute(v16, "name", &customCaption);
          v19 = UFG::qMalloc(0x18ui64, "VehicleEffectManager", 0i64);
          v20 = v19;
          if ( v19 )
          {
            v19->mNext = v19;
            v19[1].mNext = v19;
            LODWORD(v19[2].mNext) = UFG::qStringHashUpper32(v18, -1);
          }
          else
          {
            v20 = 0i64;
          }
          mNext = v17->mNext;
          mNext[1].mNext = v20;
          v20->mNext = mNext;
          v20[1].mNext = v17;
          v17->mNext = v20;
          v16 = SimpleXML::XMLDocument::GetNode(doc, 0i64, v16);
        }
        while ( v16 );
      }
      UFG::qBaseTreeRB::Add(v22, (UFG::qBaseNodeRB *)v14);
      ChildNode = SimpleXML::XMLDocument::GetNode(doc, 0i64, ChildNode);
    }
    while ( ChildNode );
  }
  UFG::qBaseTreeRB::Add(&this->mDamageTransferNodes.mTree, x);
}

// File Line: 136
// RVA: 0x6701F0
void __fastcall UFG::VehicleEffectManager::AddVehicleEffect(
        UFG::VehicleEffectManager *this,
        SimpleXML::XMLDocument *doc,
        SimpleXML::XMLNode *node)
{
  SimpleXML::XMLNode *ChildNode; // rax
  char *Attribute; // rsi
  UFG::allocator::free_link *v7; // r14
  char *v8; // rbx
  int v9; // eax
  SimpleXML::XMLNode *v10; // rdi
  UFG::allocator::free_link *v11; // r15
  char *v12; // rbx
  int v13; // eax
  SimpleXML::XMLNode *v14; // rbp
  char *Name; // rax
  UFG::allocator::free_link *v16; // rbx
  char *v17; // rax
  __int64 v18; // rax
  __int64 v19; // r13
  char *v20; // rax
  char *v21; // rax
  char *v22; // rax
  char *v23; // rax
  char *v24; // rax
  char *v25; // rbx
  int v26; // eax
  _DWORD *v27; // rdi
  const char **v28; // rsi
  __int64 v29; // r14
  char *v30; // rbx
  int v31; // eax
  UFG::qString *v32; // rcx
  char *v33; // rax
  int mNext; // eax
  UFG::allocator::free_link *v35; // rax
  UFG::allocator::free_link *v36; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  char *v39; // rax
  double v40; // xmm0_8
  float v41; // xmm7_4
  double v42; // xmm0_8
  float v43; // xmm6_4
  double v44; // xmm0_8
  UFG::qBaseTreeRB *v45; // [rsp+20h] [rbp-F8h]
  SimpleXML::XMLNode *v46; // [rsp+28h] [rbp-F0h]
  UFG::allocator::free_link *v47; // [rsp+38h] [rbp-E0h]
  UFG::qSymbolUC v48; // [rsp+40h] [rbp-D8h] BYREF
  UFG::qSymbol v49; // [rsp+44h] [rbp-D4h] BYREF
  UFG::qSymbolUC v50; // [rsp+48h] [rbp-D0h] BYREF
  UFG::allocator::free_link *v51; // [rsp+50h] [rbp-C8h]
  UFG::qString v52; // [rsp+58h] [rbp-C0h] BYREF
  __int64 v53; // [rsp+80h] [rbp-98h]
  UFG::qString v54; // [rsp+88h] [rbp-90h] BYREF
  UFG::allocator::free_link *result; // [rsp+138h] [rbp+20h] BYREF

  v53 = -2i64;
  ChildNode = SimpleXML::XMLDocument::GetChildNode(doc, "Overrides", node);
  Attribute = 0i64;
  if ( ChildNode )
    Attribute = SimpleXML::XMLNode::GetAttribute(ChildNode, "Name", &customCaption);
  v7 = UFG::qMalloc(0x70ui64, "VehicleEffectManager", 0i64);
  v47 = v7;
  result = v7;
  if ( v7 )
  {
    v8 = SimpleXML::XMLNode::GetAttribute(node, "Name", &customCaption);
    v9 = UFG::qStringHashUpper32(v8, -1);
    v7->mNext = 0i64;
    v7[1].mNext = 0i64;
    v7[2].mNext = 0i64;
    LODWORD(v7[3].mNext) = v9;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&v7[4], v8);
    UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&v7[5]);
  }
  else
  {
    v7 = 0i64;
    v47 = 0i64;
  }
  HIDWORD(v7[4].mNext) = UFG::qStringHashUpper32(Attribute, -1);
  v10 = SimpleXML::XMLDocument::GetChildNode(doc, "State", node);
  v46 = v10;
  if ( v10 )
  {
    v45 = (UFG::qBaseTreeRB *)&v7[5];
    do
    {
      v11 = UFG::qMalloc(0x78ui64, "VehicleEffectManager", 0i64);
      v51 = v11;
      if ( v11 )
      {
        v12 = SimpleXML::XMLNode::GetAttribute(v10, "Name", &customCaption);
        v13 = UFG::qStringHash32(v12, 0xFFFFFFFF);
        v11->mNext = 0i64;
        v11[1].mNext = 0i64;
        v11[2].mNext = 0i64;
        LODWORD(v11[3].mNext) = v13;
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v11[4], v12);
        UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&v11[5]);
        v11[14].mNext = 0i64;
      }
      else
      {
        v11 = 0i64;
      }
      v14 = SimpleXML::XMLDocument::GetChildNode(doc, 0i64, v10);
      if ( v14 )
      {
        while ( 1 )
        {
          Name = SimpleXML::XMLNode::GetName(v14);
          if ( (unsigned int)UFG::qStringCompare("Effect", Name, -1) )
          {
            v33 = SimpleXML::XMLNode::GetName(v14);
            if ( (unsigned int)UFG::qStringCompare("Phantom", v33, -1) )
              goto LABEL_36;
            mNext = (int)v11[4].mNext;
            if ( mNext != EngineBlown_SYMBOL.mUID && mNext != Destroyed_SYMBOL.mUID )
              goto LABEL_36;
            if ( v11[14].mNext )
              goto LABEL_36;
            v35 = UFG::qMalloc(0x10ui64, "VehiclePhantom", 0i64);
            v36 = v35;
            if ( v35 )
            {
              LODWORD(v35->mNext) = -1;
              y = UFG::qVector3::msZero.y;
              z = UFG::qVector3::msZero.z;
              HIDWORD(v35->mNext) = LODWORD(UFG::qVector3::msZero.x);
              *(float *)&v35[1].mNext = y;
              *((float *)&v35[1].mNext + 1) = z;
            }
            else
            {
              v36 = 0i64;
            }
            v39 = SimpleXML::XMLNode::GetAttribute(v14, "Marker", &customCaption);
            UFG::qString::qString(&v54, v39);
            LODWORD(v36->mNext) = UFG::qStringHashUpper32(v54.mData, -1);
            v40 = SimpleXML::XMLNode::GetAttribute(v14, "X", 0.0);
            v41 = *(float *)&v40;
            v42 = SimpleXML::XMLNode::GetAttribute(v14, "Y", 0.0);
            v43 = *(float *)&v42;
            v44 = SimpleXML::XMLNode::GetAttribute(v14, "Z", 0.0);
            *((float *)&v36->mNext + 1) = v41 * 0.5;
            *(float *)&v36[1].mNext = v43 * 0.5;
            *((float *)&v36[1].mNext + 1) = *(float *)&v44 * 0.5;
            v11[14].mNext = v36;
            v32 = &v54;
          }
          else
          {
            v16 = UFG::qMalloc(0x78ui64, "VehicleEffectManager", 0i64);
            if ( v16 )
            {
              v17 = SimpleXML::XMLNode::GetAttribute(v14, "Name", &customCaption);
              UFG::VehicleEffect::VehicleEffect((UFG::VehicleEffect *)v16, v17);
              v19 = v18;
            }
            else
            {
              v19 = 0i64;
            }
            v20 = SimpleXML::XMLNode::GetAttribute(v14, "Marker", &customCaption);
            UFG::qString::qString(&v52, v20);
            *(UFG::qSymbolUC *)(v19 + 44) = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(
                                                              (UFG::qSymbolUC *)&result,
                                                              v52.mData)->mUID;
            UFG::qString::ReplaceString(&v52, "E_", "D_", 0);
            *(UFG::qSymbolUC *)(v19 + 92) = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&v48, v52.mData)->mUID;
            v21 = SimpleXML::XMLNode::GetAttribute(v14, "ForwardBone", &customCaption);
            *(_DWORD *)(v19 + 72) = UFG::qStringHashUpper32(v21, -1);
            v22 = SimpleXML::XMLNode::GetAttribute(v14, "RearBone", &customCaption);
            *(_DWORD *)(v19 + 76) = UFG::qStringHashUpper32(v22, -1);
            v23 = SimpleXML::XMLNode::GetAttribute(v14, "DamageAffector", &customCaption);
            *(UFG::qSymbolUC *)(v19 + 84) = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&v50, v23)->mUID;
            v24 = SimpleXML::XMLNode::GetAttribute(v14, "Transform", &customCaption);
            *(UFG::qSymbol *)(v19 + 36) = (UFG::qSymbol)UFG::qSymbol::create_from_string(&v49, v24)->mUID;
            v25 = SimpleXML::XMLNode::GetAttribute(v14, "BoundEffect", &customCaption);
            if ( (unsigned int)UFG::qStringCompare(v25, &customCaption, -1) )
              v26 = UFG::qStringHashUpper32(v25, -1);
            else
              v26 = 0;
            v27 = (_DWORD *)(v19 + 48);
            *(_DWORD *)(v19 + 48) = v26;
            v28 = (const char **)&unk_142434AD8;
            v29 = 4i64;
            do
            {
              v30 = SimpleXML::XMLNode::GetAttribute(v14, *v28, undefinedEffect);
              if ( (unsigned int)UFG::qStringCompare(v30, undefinedEffect, -1) )
              {
                if ( (unsigned int)UFG::qStringCompare(v30, &customCaption, -1) )
                  v31 = UFG::qStringHashUpper32(v30, -1);
                else
                  v31 = 0;
                *v27 = v31;
              }
              ++v27;
              v28 += 5;
              --v29;
            }
            while ( v29 );
            UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&v11[5], (UFG::qBaseNodeRB *)v19);
            v32 = &v52;
          }
          UFG::qString::~qString(v32);
LABEL_36:
          v14 = SimpleXML::XMLDocument::GetNode(doc, 0i64, v14);
          if ( !v14 )
          {
            v10 = v46;
            break;
          }
        }
      }
      UFG::qBaseTreeRB::Add(v45, (UFG::qBaseNodeRB *)v11);
      v10 = SimpleXML::XMLDocument::GetNode(doc, 0i64, v10);
      v46 = v10;
    }
    while ( v10 );
    v7 = v47;
  }
  UFG::qBaseTreeRB::Add(&this->mVehicleEffectTemplates.mTree, (UFG::qBaseNodeRB *)v7);
}

// File Line: 243
// RVA: 0x67DA70
void __fastcall UFG::VehicleEffectManager::Init(UFG::VehicleEffectManager *this)
{
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // rbx
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *i; // rdi
  SimpleXML::XMLDocument *v6; // rax
  SimpleXML::XMLDocument *v7; // rbx
  SimpleXML::XMLNode *v8; // rax
  SimpleXML::XMLNode *j; // rdi

  v2 = SimpleXML::XMLDocument::Open("Data\\FX\\VehicleSFXSetup.xml", 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    Node = SimpleXML::XMLDocument::GetNode(v2, "VehicleEffectsDefinition", 0i64);
    for ( i = SimpleXML::XMLDocument::GetChildNode(v3, "VehicleEffects", Node);
          i;
          i = SimpleXML::XMLDocument::GetNode(v3, 0i64, i) )
    {
      UFG::VehicleEffectManager::AddVehicleEffect(this, v3, i);
    }
    SimpleXML::XMLDocument::~XMLDocument(v3);
    operator delete[](v3);
  }
  v6 = SimpleXML::XMLDocument::Open("data\\vehicles_new\\DamageTransfer.xml", 1ui64, 0i64);
  v7 = v6;
  if ( v6 )
  {
    v8 = SimpleXML::XMLDocument::GetNode(v6, "DamageTransferSystem", 0i64);
    for ( j = SimpleXML::XMLDocument::GetChildNode(v7, "DamageTransfer", v8);
          j;
          j = SimpleXML::XMLDocument::GetNode(v7, 0i64, j) )
    {
      UFG::VehicleEffectManager::AddDamageTransferNode(this, v7, j);
    }
    SimpleXML::XMLDocument::~XMLDocument(v7);
    operator delete[](v7);
  }
}

