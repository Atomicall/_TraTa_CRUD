public class ComplexNumberInAlgebraicForm extends AbstractComplexNumber {
    public static float real = 0;
    public static float im = 0;

    @Override
    void Add(AlgebraicFormStorage n) {
        super.Add(n);
    }

    @Override
    void Sub(AlgebraicFormStorage n) {
        super.Sub(n);
    }

    @Override
    void Mul(AlgebraicFormStorage n) {
        super.Mul(n);
    }

    @Override
    void Div(AlgebraicFormStorage n) {
        super.Div(n);
    }

    ExponentialFormStorage getInComplexForm() {
        return new ExponentialFormStorage(real, im);
    }


}
