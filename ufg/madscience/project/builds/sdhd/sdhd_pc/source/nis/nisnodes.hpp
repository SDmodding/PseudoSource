// File Line: 292
// RVA: 0x3E2240
void __fastcall NISActorNode::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x118ui64, "MemberMap::NISActorNode", 0i64, 1u);
  if ( v0 )
    NISActorNode::NISActorNode((NISActorNode *)v0);
}

