// File Line: 34
// RVA: 0x26C960
void __fastcall StimulusBank::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB8ui64, "MemberMap::StimulusBank", 0i64, 1u);
  if ( v0 )
    StimulusBank::StimulusBank((StimulusBank *)v0);
}

