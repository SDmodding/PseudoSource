// File Line: 20
// RVA: 0x452090
void __fastcall UFG::AIVehicleAttachment::operator delete(char *ptr, const char *name)
{
  UFG::qMemoryPool::Free(&gAIMemoryPool, ptr);
}

