// File Line: 22
// RVA: 0x1582B50
__int64 dynamic_initializer_for__gBoundEffectSpeed__()
{
  UFG::qString::qString(gBoundEffectSpeed, "Speed0");
  UFG::qString::qString(&stru_142434AE8, "Speed1");
  UFG::qString::qString(&stru_142434B10, "Speed2");
  UFG::qString::qString(&stru_142434B38, "Speed3");
  return atexit(dynamic_atexit_destructor_for__gBoundEffectSpeed__);
}

// File Line: 25
// RVA: 0x157B9F0
__int64 dynamic_initializer_for__EngineBlown_SYMBOL__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("EngineBlown", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&EngineBlown_SYMBOL, v0);
  return atexit(dynamic_atexit_destructor_for__EngineBlown_SYMBOL__);
}

// File Line: 26
// RVA: 0x157B9B0
__int64 dynamic_initializer_for__Destroyed_SYMBOL__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Destroyed", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&Destroyed_SYMBOL, v0);
  return atexit(dynamic_atexit_destructor_for__Destroyed_SYMBOL__);
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
void __usercall UFG::VehicleEffectManager::AddDamageTransferNode(UFG::VehicleEffectManager *this@<rcx>, SimpleXML::XMLDocument *doc@<rdx>, SimpleXML::XMLNode *node@<r8>, float a4@<xmm0>)
{
  SimpleXML::XMLNode *v4; // rbx
  SimpleXML::XMLDocument *v5; // r13
  char *v6; // rdi
  float v7; // xmm8_4
  UFG::allocator::free_link *v8; // rsi
  int v9; // eax
  SimpleXML::XMLNode *v10; // r12
  char *v11; // rbx
  float v12; // xmm6_4
  UFG::allocator::free_link *v13; // r14
  int v14; // eax
  UFG::allocator::free_link *v15; // ST38_8
  SimpleXML::XMLNode *v16; // rdi
  UFG::allocator::free_link *v17; // rsi
  char *v18; // r15
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rbx
  UFG::allocator::free_link *v21; // rax
  UFG::qBaseTreeRB *v22; // [rsp+20h] [rbp-98h]
  UFG::VehicleEffectManager *v23; // [rsp+C0h] [rbp+8h]
  UFG::qBaseNodeRB *x; // [rsp+D8h] [rbp+20h]

  v23 = this;
  v4 = node;
  v5 = doc;
  v6 = SimpleXML::XMLNode::GetAttribute(node, "name", &customWorldMapCaption);
  SimpleXML::XMLNode::GetAttribute(v4, "DefaultValue", 1.0);
  v7 = a4;
  if ( SimpleXML::XMLNode::GetAttribute(v4, "IsDefaultInfinite", 0) )
    v7 = FLOAT_N1_0;
  v8 = UFG::qMalloc(0x70ui64, "VehicleEffectManager", 0i64);
  x = (UFG::qBaseNodeRB *)v8;
  if ( v8 )
  {
    v9 = UFG::qStringHashUpper32(v6, 0xFFFFFFFF);
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
  v10 = SimpleXML::XMLDocument::GetChildNode(v5, "DamageAffector", v4);
  if ( v10 )
  {
    v22 = (UFG::qBaseTreeRB *)&v8[4];
    do
    {
      v11 = SimpleXML::XMLNode::GetAttribute(v10, "name", &customWorldMapCaption);
      v12 = v7;
      if ( !SimpleXML::XMLNode::GetAttribute(v10, "UseDefault", 1) )
      {
        SimpleXML::XMLNode::GetAttribute(v10, "Health", 1.0);
        v12 = a4;
        if ( SimpleXML::XMLNode::GetAttribute(v10, "Invincible", 0) )
          v12 = FLOAT_N1_0;
      }
      v13 = UFG::qMalloc(0x38ui64, "VehicleEffectManager", 0i64);
      if ( v13 )
      {
        v14 = UFG::qStringHashUpper32(v11, 0xFFFFFFFF);
        v13->mNext = 0i64;
        v13[1].mNext = 0i64;
        v13[2].mNext = 0i64;
        LODWORD(v13[3].mNext) = v14;
        v15 = v13 + 4;
        v15->mNext = v15;
        v15[1].mNext = v15;
        *(float *)&v13[6].mNext = v12;
      }
      else
      {
        v13 = 0i64;
      }
      v16 = SimpleXML::XMLDocument::GetChildNode(v5, "TransferTo", v10);
      if ( v16 )
      {
        v17 = v13 + 4;
        do
        {
          v18 = SimpleXML::XMLNode::GetAttribute(v16, "name", &customWorldMapCaption);
          v19 = UFG::qMalloc(0x18ui64, "VehicleEffectManager", 0i64);
          v20 = v19;
          if ( v19 )
          {
            v19->mNext = v19;
            v19[1].mNext = v19;
            LODWORD(v19[2].mNext) = UFG::qStringHashUpper32(v18, 0xFFFFFFFF);
          }
          else
          {
            v20 = 0i64;
          }
          v21 = v17->mNext;
          v21[1].mNext = v20;
          v20->mNext = v21;
          v20[1].mNext = v17;
          v17->mNext = v20;
          v16 = SimpleXML::XMLDocument::GetNode(v5, 0i64, v16);
        }
        while ( v16 );
      }
      UFG::qBaseTreeRB::Add(v22, (UFG::qBaseNodeRB *)v13);
      v10 = SimpleXML::XMLDocument::GetNode(v5, 0i64, v10);
    }
    while ( v10 );
  }
  UFG::qBaseTreeRB::Add(&v23->mDamageTransferNodes.mTree, x);
}

// File Line: 136
// RVA: 0x6701F0
void __usercall UFG::VehicleEffectManager::AddVehicleEffect(UFG::VehicleEffectManager *this@<rcx>, SimpleXML::XMLDocument *doc@<rdx>, SimpleXML::XMLNode *node@<r8>, float a4@<xmm0>)
{
  SimpleXML::XMLNode *v4; // rdi
  SimpleXML::XMLDocument *v5; // r12
  SimpleXML::XMLNode *v6; // rax
  char *v7; // rsi
  UFG::allocator::free_link *v8; // r14
  char *v9; // rax
  const char *v10; // rbx
  int v11; // eax
  SimpleXML::XMLNode *v12; // rdi
  UFG::allocator::free_link *v13; // r15
  char *v14; // rax
  const char *v15; // rbx
  int v16; // eax
  SimpleXML::XMLNode *v17; // rbp
  char *v18; // rax
  UFG::allocator::free_link *v19; // rbx
  char *v20; // rax
  __int64 v21; // rax
  __int64 v22; // r13
  char *v23; // rax
  char *v24; // rax
  char *v25; // rax
  char *v26; // rax
  char *v27; // rax
  char *v28; // rbx
  int v29; // eax
  _DWORD *v30; // rdi
  const char **v31; // rsi
  signed __int64 v32; // r14
  char *v33; // rbx
  int v34; // eax
  UFG::qString *v35; // rcx
  char *v36; // rax
  int v37; // eax
  UFG::allocator::free_link *v38; // rax
  UFG::allocator::free_link *v39; // rbx
  float v40; // xmm1_4
  float v41; // xmm2_4
  char *v42; // rax
  UFG::qBaseTreeRB *v43; // [rsp+20h] [rbp-F8h]
  SimpleXML::XMLNode *v44; // [rsp+28h] [rbp-F0h]
  UFG::allocator::free_link *v45; // [rsp+38h] [rbp-E0h]
  UFG::qSymbolUC v46; // [rsp+40h] [rbp-D8h]
  UFG::qSymbol v47; // [rsp+44h] [rbp-D4h]
  UFG::qSymbolUC v48; // [rsp+48h] [rbp-D0h]
  UFG::allocator::free_link *v49; // [rsp+50h] [rbp-C8h]
  UFG::qString v50; // [rsp+58h] [rbp-C0h]
  __int64 v51; // [rsp+80h] [rbp-98h]
  UFG::qString v52; // [rsp+88h] [rbp-90h]
  UFG::VehicleEffectManager *v53; // [rsp+120h] [rbp+8h]
  UFG::allocator::free_link *result; // [rsp+138h] [rbp+20h]

  v53 = this;
  v51 = -2i64;
  v4 = node;
  v5 = doc;
  v6 = SimpleXML::XMLDocument::GetChildNode(doc, "Overrides", node);
  v7 = 0i64;
  if ( v6 )
    v7 = SimpleXML::XMLNode::GetAttribute(v6, "Name", &customWorldMapCaption);
  v8 = UFG::qMalloc(0x70ui64, "VehicleEffectManager", 0i64);
  v45 = v8;
  result = v8;
  if ( v8 )
  {
    v9 = SimpleXML::XMLNode::GetAttribute(v4, "Name", &customWorldMapCaption);
    v10 = v9;
    v11 = UFG::qStringHashUpper32(v9, 0xFFFFFFFF);
    v8->mNext = 0i64;
    v8[1].mNext = 0i64;
    v8[2].mNext = 0i64;
    LODWORD(v8[3].mNext) = v11;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&v8[4], v10);
    UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&v8[5]);
  }
  else
  {
    v8 = 0i64;
    v45 = 0i64;
  }
  HIDWORD(v8[4].mNext) = UFG::qStringHashUpper32(v7, 0xFFFFFFFF);
  v12 = SimpleXML::XMLDocument::GetChildNode(v5, "State", v4);
  v44 = v12;
  if ( v12 )
  {
    v43 = (UFG::qBaseTreeRB *)&v8[5];
    do
    {
      v13 = UFG::qMalloc(0x78ui64, "VehicleEffectManager", 0i64);
      v49 = v13;
      if ( v13 )
      {
        v14 = SimpleXML::XMLNode::GetAttribute(v12, "Name", &customWorldMapCaption);
        v15 = v14;
        v16 = UFG::qStringHash32(v14, 0xFFFFFFFF);
        v13->mNext = 0i64;
        v13[1].mNext = 0i64;
        v13[2].mNext = 0i64;
        LODWORD(v13[3].mNext) = v16;
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v13[4], v15);
        UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&v13[5]);
        v13[14].mNext = 0i64;
      }
      else
      {
        v13 = 0i64;
      }
      v17 = SimpleXML::XMLDocument::GetChildNode(v5, 0i64, v12);
      if ( v17 )
      {
        while ( 1 )
        {
          v18 = SimpleXML::XMLNode::GetName(v17);
          if ( (unsigned int)UFG::qStringCompare("Effect", v18, -1) )
          {
            v36 = SimpleXML::XMLNode::GetName(v17);
            if ( (unsigned int)UFG::qStringCompare("Phantom", v36, -1) )
              goto LABEL_36;
            v37 = (int)v13[4].mNext;
            if ( v37 != EngineBlown_SYMBOL.mUID && v37 != Destroyed_SYMBOL.mUID )
              goto LABEL_36;
            if ( v13[14].mNext )
              goto LABEL_36;
            v38 = UFG::qMalloc(0x10ui64, "VehiclePhantom", 0i64);
            v39 = v38;
            if ( v38 )
            {
              LODWORD(v38->mNext) = -1;
              v40 = UFG::qVector3::msZero.y;
              v41 = UFG::qVector3::msZero.z;
              a4 = UFG::qVector3::msZero.x;
              HIDWORD(v38->mNext) = LODWORD(UFG::qVector3::msZero.x);
              *(float *)&v38[1].mNext = v40;
              *((float *)&v38[1].mNext + 1) = v41;
            }
            else
            {
              v39 = 0i64;
            }
            v42 = SimpleXML::XMLNode::GetAttribute(v17, "Marker", &customWorldMapCaption);
            UFG::qString::qString(&v52, v42);
            LODWORD(v39->mNext) = UFG::qStringHashUpper32(v52.mData, 0xFFFFFFFF);
            SimpleXML::XMLNode::GetAttribute(v17, "X", 0.0);
            SimpleXML::XMLNode::GetAttribute(v17, "Y", 0.0);
            SimpleXML::XMLNode::GetAttribute(v17, "Z", 0.0);
            *((float *)&v39->mNext + 1) = a4 * 0.5;
            *(float *)&v39[1].mNext = a4 * 0.5;
            a4 = a4 * 0.5;
            *((float *)&v39[1].mNext + 1) = a4;
            v13[14].mNext = v39;
            v35 = &v52;
          }
          else
          {
            v19 = UFG::qMalloc(0x78ui64, "VehicleEffectManager", 0i64);
            if ( v19 )
            {
              v20 = SimpleXML::XMLNode::GetAttribute(v17, "Name", &customWorldMapCaption);
              UFG::VehicleEffect::VehicleEffect((UFG::VehicleEffect *)v19, v20);
              v22 = v21;
            }
            else
            {
              v22 = 0i64;
            }
            v23 = SimpleXML::XMLNode::GetAttribute(v17, "Marker", &customWorldMapCaption);
            UFG::qString::qString(&v50, v23);
            *(UFG::qSymbolUC *)(v22 + 44) = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(
                                                              (UFG::qSymbolUC *)&result,
                                                              v50.mData)->mUID;
            UFG::qString::ReplaceString(&v50, "E_", "D_", 0);
            *(UFG::qSymbolUC *)(v22 + 92) = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&v46, v50.mData)->mUID;
            v24 = SimpleXML::XMLNode::GetAttribute(v17, "ForwardBone", &customWorldMapCaption);
            *(_DWORD *)(v22 + 72) = UFG::qStringHashUpper32(v24, 0xFFFFFFFF);
            v25 = SimpleXML::XMLNode::GetAttribute(v17, "RearBone", &customWorldMapCaption);
            *(_DWORD *)(v22 + 76) = UFG::qStringHashUpper32(v25, 0xFFFFFFFF);
            v26 = SimpleXML::XMLNode::GetAttribute(v17, "DamageAffector", &customWorldMapCaption);
            *(UFG::qSymbolUC *)(v22 + 84) = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&v48, v26)->mUID;
            v27 = SimpleXML::XMLNode::GetAttribute(v17, "Transform", &customWorldMapCaption);
            *(UFG::qSymbol *)(v22 + 36) = (UFG::qSymbol)UFG::qSymbol::create_from_string(&v47, v27)->mUID;
            v28 = SimpleXML::XMLNode::GetAttribute(v17, "BoundEffect", &customWorldMapCaption);
            if ( (unsigned int)UFG::qStringCompare(v28, &customWorldMapCaption, -1) )
              v29 = UFG::qStringHashUpper32(v28, 0xFFFFFFFF);
            else
              v29 = 0;
            v30 = (_DWORD *)(v22 + 48);
            *(_DWORD *)(v22 + 48) = v29;
            v31 = (const char **)&unk_142434AD8;
            v32 = 4i64;
            do
            {
              v33 = SimpleXML::XMLNode::GetAttribute(v17, *v31, undefinedEffect);
              if ( (unsigned int)UFG::qStringCompare(v33, undefinedEffect, -1) )
              {
                if ( (unsigned int)UFG::qStringCompare(v33, &customWorldMapCaption, -1) )
                  v34 = UFG::qStringHashUpper32(v33, 0xFFFFFFFF);
                else
                  v34 = 0;
                *v30 = v34;
              }
              ++v30;
              v31 += 5;
              --v32;
            }
            while ( v32 );
            UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&v13[5], (UFG::qBaseNodeRB *)v22);
            v35 = &v50;
          }
          UFG::qString::~qString(v35);
LABEL_36:
          v17 = SimpleXML::XMLDocument::GetNode(v5, 0i64, v17);
          if ( !v17 )
          {
            v12 = v44;
            break;
          }
        }
      }
      UFG::qBaseTreeRB::Add(v43, (UFG::qBaseNodeRB *)v13);
      v12 = SimpleXML::XMLDocument::GetNode(v5, 0i64, v12);
      v44 = v12;
    }
    while ( v12 );
    v8 = v45;
  }
  UFG::qBaseTreeRB::Add(&v53->mVehicleEffectTemplates.mTree, (UFG::qBaseNodeRB *)v8);
}

// File Line: 243
// RVA: 0x67DA70
void __usercall UFG::VehicleEffectManager::Init(UFG::VehicleEffectManager *this@<rcx>, float a2@<xmm0>)
{
  UFG::VehicleEffectManager *v2; // rsi
  SimpleXML::XMLDocument *v3; // rax
  SimpleXML::XMLDocument *v4; // rbx
  SimpleXML::XMLNode *v5; // rax
  SimpleXML::XMLNode *i; // rdi
  SimpleXML::XMLDocument *v7; // rax
  SimpleXML::XMLDocument *v8; // rbx
  SimpleXML::XMLNode *v9; // rax
  SimpleXML::XMLNode *j; // rdi

  v2 = this;
  v3 = SimpleXML::XMLDocument::Open("Data\\FX\\VehicleSFXSetup.xml", 1ui64, 0i64);
  v4 = v3;
  if ( v3 )
  {
    v5 = SimpleXML::XMLDocument::GetNode(v3, "VehicleEffectsDefinition", 0i64);
    for ( i = SimpleXML::XMLDocument::GetChildNode(v4, "VehicleEffects", v5);
          i;
          i = SimpleXML::XMLDocument::GetNode(v4, 0i64, i) )
    {
      UFG::VehicleEffectManager::AddVehicleEffect(v2, v4, i, a2);
    }
    SimpleXML::XMLDocument::~XMLDocument(v4);
    operator delete[](v4);
  }
  v7 = SimpleXML::XMLDocument::Open("data\\vehicles_new\\DamageTransfer.xml", 1ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    v9 = SimpleXML::XMLDocument::GetNode(v7, "DamageTransferSystem", 0i64);
    for ( j = SimpleXML::XMLDocument::GetChildNode(v8, "DamageTransfer", v9);
          j;
          j = SimpleXML::XMLDocument::GetNode(v8, 0i64, j) )
    {
      UFG::VehicleEffectManager::AddDamageTransferNode(v2, v8, j, a2);
    }
    SimpleXML::XMLDocument::~XMLDocument(v8);
    operator delete[](v8);
  }
}

