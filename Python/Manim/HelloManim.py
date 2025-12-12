from manim import * # type: ignore
class SquareToCircle(Scene):
    def construct(self):
        square = Square(side_length=2,color=BLUE)
        circle = Circle(radius=1,color=RED)
        circle.move_to(square.get_center())
        self.play(FadeIn(square))
        self.wait(1)
        self.play(Transform(square, circle))
        self.wait(1)
        self.play(FadeOut(square))
        self.wait(1)
        self.clear()
        
        text = Text("Hello Manim",font_size=32,color=BLUE)
        self.play(Write(text))
        self.wait(1)
        pass
    pass
SquareToCircle().render()