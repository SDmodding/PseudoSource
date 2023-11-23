// File Line: 37
// RVA: 0x251CC0
const char *__fastcall UEL::ArgumentExpression::GetClassname(UEL::ArgumentExpression *this)
{
  return "ArgumentExpression";
}

// File Line: 41
// RVA: 0x24F690
UEL::Value *__fastcall UEL::ArgumentExpression::Eval(
        UEL::ArgumentExpression *this,
        UEL::Value *result,
        UEL::ParametersBase *parameters,
        UFG::qArray<UEL::Value,0> *args)
{
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  return result;
}

// File Line: 64
// RVA: 0x251CD0
const char *__fastcall UEL::ArgumentUsageExpression::GetClassname(UEL::ArgumentUsageExpression *this)
{
  return "ArgumentUsageExpression";
}

