from manim import * # type: ignore
class MoveBox(Scene):
    def construct(self) -> None:
        axes = Axes(
            x_range=[-10,10,2],
            y_range=[-10,10,2],
            x_length=10,
            y_length=10,
            axis_config={"color": BLUE,
                        "include_numbers": True},
        )
        scale_factor = 0.7
        axes.scale(scale_factor)

        box = Rectangle(stroke_color=GREEN_C,stroke_opacity=0.3,
                        fill_color=RED,fill_opacity=0.5,height=1,width=1)
        box.move_to(axes.c2p(0,0))
        
        self.add(axes)
        self.add(box)
        self.play(box.animate.shift(RIGHT * 2 * scale_factor),run_time=2)
        self.play(box.animate.shift(UP * 3 * scale_factor),run_time=2)
        self.play(box.animate.shift(LEFT * 4 * scale_factor),run_time=3)
        self.wait()

        text = Text("Move The Box",font_size=32,color=YELLOW)
        text.to_edge(DOWN, buff=0.5).to_edge(RIGHT, buff=0.5)
        self.play(Write(text))
        self.wait(2)
MoveBox().render()