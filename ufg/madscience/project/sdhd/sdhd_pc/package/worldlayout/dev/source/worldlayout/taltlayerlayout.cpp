// File Line: 30
// RVA: 0x15876C0
__int64 UFG::_dynamic_initializer_for__BASE_LAYER_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32(UFG::BASE_LAYER_NAME, 0xFFFFFFFF);
  UFG::BASE_LAYER_UID = result;
  return result;
}

