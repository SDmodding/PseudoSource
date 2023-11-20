// File Line: 82
// RVA: 0x15C0F70
void dynamic_initializer_for__hkaiDirectedGraphExplicitCostNodeClass__()
{
  hkClass::hkClass(
    &hkaiDirectedGraphExplicitCostNodeClass,
    "hkaiDirectedGraphExplicitCostNode",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaiDirectedGraphExplicitCost_NodeClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 85
// RVA: 0xBB6550
hkClass *__fastcall hkaiDirectedGraphExplicitCost::Node::staticClass()
{
  return &hkaiDirectedGraphExplicitCostNodeClass;
}

// File Line: 92
// RVA: 0xBB6570
void __fastcall cleanupLoadedObjecthkaiDirectedGraphExplicitCostNode(void *p)
{
  ;
}

// File Line: 112
// RVA: 0x15C0E70
hkClassEnum *dynamic_initializer_for__hkaiDirectedGraphExplicitCost::Edge::Members__()
{
  hkClassEnum *result; // rax

  result = hkaiDirectedGraphExplicitCostEdgeBitsEnum;
  unk_142104698 = hkaiDirectedGraphExplicitCostEdgeBitsEnum;
  return result;
}

// File Line: 129
// RVA: 0x15C0F00
void dynamic_initializer_for__hkaiDirectedGraphExplicitCostEdgeClass__()
{
  hkClass::hkClass(
    &hkaiDirectedGraphExplicitCostEdgeClass,
    "hkaiDirectedGraphExplicitCostEdge",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaiDirectedGraphExplicitCost::Edge::Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 132
// RVA: 0xBB6560
hkClass *__fastcall hkaiDirectedGraphExplicitCost::Edge::staticClass()
{
  return &hkaiDirectedGraphExplicitCostEdgeClass;
}

// File Line: 139
// RVA: 0xBB6580
void __fastcall cleanupLoadedObjecthkaiDirectedGraphExplicitCostEdge(void *p)
{
  ;
}

// File Line: 204
// RVA: 0x15C0E80
void dynamic_initializer_for__hkaiDirectedGraphExplicitCostClass__()
{
  hkClass::hkClass(
    &hkaiDirectedGraphExplicitCostClass,
    "hkaiDirectedGraphExplicitCost",
    &hkReferencedObjectClass,
    120,
    0i64,
    0,
    &hkaiDirectedGraphExplicitCostEnums,
    2,
    &hkaiDirectedGraphExplicitCostClass_Members,
    8,
    &hkaiDirectedGraphExplicitCost_Default,
    0i64,
    0,
    7u);
}

// File Line: 207
// RVA: 0xBB6540
hkClass *__fastcall hkaiDirectedGraphExplicitCost::staticClass()
{
  return &hkaiDirectedGraphExplicitCostClass;
}

// File Line: 214
// RVA: 0xBB6590
void __fastcall finishLoadedObjecthkaiDirectedGraphExplicitCost(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiDirectedGraphExplicitCost::hkaiDirectedGraphExplicitCost);
}

// File Line: 220
// RVA: 0xBB65B0
void __fastcall cleanupLoadedObjecthkaiDirectedGraphExplicitCost(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 224
// RVA: 0xBB65C0
hkBaseObjectVtbl *__fastcall getVtablehkaiDirectedGraphExplicitCost()
{
  hkaiDirectedGraphExplicitCost v1; // [rsp+20h] [rbp-88h]

  hkaiDirectedGraphExplicitCost::hkaiDirectedGraphExplicitCost(&v1, 0);
  return v1.vfptr;
}

// File Line: 246
// RVA: 0x15C0FE0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiDirectedGraphExplicitCostTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiDirectedGraphExplicitCost();
  hkaiDirectedGraphExplicitCostTypeInfo.m_size = 120i64;
  hkaiDirectedGraphExplicitCostTypeInfo.m_typeName = "hkaiDirectedGraphExplicitCost";
  hkaiDirectedGraphExplicitCostTypeInfo.m_vtable = result;
  hkaiDirectedGraphExplicitCostTypeInfo.m_scopedName = "!hkaiDirectedGraphExplicitCost";
  hkaiDirectedGraphExplicitCostTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiDirectedGraphExplicitCost;
  hkaiDirectedGraphExplicitCostTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiDirectedGraphExplicitCost;
  return result;
}

