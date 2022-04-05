package me.divium.rectangle;

import org.junit.Assert;
import org.junit.Test;
import org.junit.jupiter.api.DisplayName;

public class LineTest {

    @Test
    @DisplayName("Should create valid object")
    public void constructor() {
        Assert.assertThrows(IllegalArgumentException.class, () -> {
           new Line(LineStyle.SOLID, -1, new Color(0, 0, 0));
        });
    }
}
