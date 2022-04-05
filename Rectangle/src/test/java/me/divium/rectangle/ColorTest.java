package me.divium.rectangle;

import org.junit.Assert;
import org.junit.Test;
import org.junit.jupiter.api.DisplayName;

public class ColorTest {

    @Test
    @DisplayName("Should create valid color class")
    public void constructor() {
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(-1, 0, 0);
        });
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, -1, 0);
        });
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, 0, -1);
        });

        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(256, 0, 0);
        });
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, 256, 0);
        });
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, 0, 256);
        });
    }

    @Test
    @DisplayName("Should set valid red color")
    public void setRed() {
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, 0, 0);
            color.setRed(-1);
        });
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, 0, 0);
            color.setRed(256);
        });

        var color = new Color(0,0,0);
        Assert.assertEquals(0, color.getRed());

        color.setRed(255);
        Assert.assertEquals(255, color.getRed());
    }

    @Test
    @DisplayName("Should set valid green color")
    public void setGreen() {
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, 0, 0);
            color.setGreen(-1);
        });
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, 0, 0);
            color.setGreen(256);
        });

        var color = new Color(0,0,0);
        Assert.assertEquals(0, color.getGreen());

        color.setGreen(255);
        Assert.assertEquals(255, color.getGreen());
    }

    @Test
    @DisplayName("Should set valid blue color")
    public void setBlue() {
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, 0, 0);
            color.setBlue(-1);
        });
        Assert.assertThrows(IllegalArgumentException.class, () -> {
            var color = new Color(0, 0, 0);
            color.setBlue(256);
        });

        var color = new Color(0,0,0);
        Assert.assertEquals(0, color.getBlue());

        color.setBlue(255);
        Assert.assertEquals(255, color.getBlue());
    }
}
