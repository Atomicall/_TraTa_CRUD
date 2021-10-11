public class ComplexNumberInExponentialForm extends  AbstractComplexNumber{

    private float mod;
    private float phase;

    @Override
    void Add(ExponentialFormStorage n) {
        super.Add(n);
    }

    @Override
    void Sub(ExponentialFormStorage n) {
        super.Sub(n);
    }

    @Override
    void Mul(ExponentialFormStorage n) {
        super.Mul(n);
    }

    @Override
    void Div(ExponentialFormStorage n) {
        super.Div(n);
    }

    AlgebraicFormStorage getInAlgebraicForm(){
        return new AlgebraicFormStorage(mod, phase);
    }
}
